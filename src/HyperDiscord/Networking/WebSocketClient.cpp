#include "WebSocketClient.h"

#include <json.hpp>

#include <algorithm>
#include <iostream>

namespace HyperDiscord
{
	WebSocketClient::WebSocketClient()
	{
		Init();
	}

	WebSocketClient::~WebSocketClient()
	{
		Shutdown();
	}

	void WebSocketClient::Init()
	{
		m_Session = WinHttpOpen(L"HyperDiscord", WINHTTP_ACCESS_TYPE_AUTOMATIC_PROXY, WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
		if (!m_Session)
		{
			std::cerr << "[HyperDiscord] Error " << GetLastError() << " in WinHttpOpen." << std::endl;
			exit(-1);
		}

		m_Connection = WinHttpConnect(m_Session, L"gateway.discord.gg", INTERNET_DEFAULT_HTTP_PORT, 0);
		if (!m_Connection)
		{
			std::cerr << "[HyperDiscord] Error " << GetLastError() << " in WinHttpConnect." << std::endl;
			exit(-1);
		}

		HINTERNET request = WinHttpOpenRequest(m_Connection, L"GET", L"/?v=8&encoding=json", nullptr, 0, 0, 0);
		if (!request)
		{
			std::cerr << "[HyperDiscord] Error " << GetLastError() << " in WinHttpOpenRequest." << std::endl;
			exit(-1);
		}

		if (!WinHttpSetOption(request, WINHTTP_OPTION_UPGRADE_TO_WEB_SOCKET, nullptr, 0))
		{
			std::cerr << "[HyperDiscord] Error " << GetLastError() << " in WinHttpSetOption." << std::endl;
			exit(-1);
		}

		if (!WinHttpSendRequest(request, WINHTTP_NO_ADDITIONAL_HEADERS, 0, WINHTTP_NO_REQUEST_DATA, 0, 0, 0))
		{
			std::cerr << "[HyperDiscord] Error " << GetLastError() << " in WinHttpSendRequest." << std::endl;
			exit(-1);
		}

		if (!WinHttpReceiveResponse(request, nullptr))
		{
			std::cerr << "[HyperDiscord] Error " << GetLastError() << " in WinHttpReceiveResponse." << std::endl;
			exit(-1);
		}

		m_WebSocket = WinHttpWebSocketCompleteUpgrade(request, 0);
		if (!m_WebSocket)
		{
			std::cerr << "[HyperDiscord] Error " << GetLastError() << " in WinHttpWebSocketCompleteUpgrade." << std::endl;
			exit(-1);
		}

		WinHttpCloseHandle(request);
	}

	void WebSocketClient::Shutdown()
	{
		if (WinHttpWebSocketClose(m_WebSocket, WINHTTP_WEB_SOCKET_SUCCESS_CLOSE_STATUS, nullptr, 0) != ERROR_SUCCESS)
		{
			std::cerr << "[HyperDiscord] Error " << GetLastError() << " in WinHttpWebSocketClose." << std::endl;
			exit(-1);
		}

		USHORT status = 0;
		BYTE reasonBuffer[123];
		DWORD reasonLength;
		std::fill(reasonBuffer, reasonBuffer + sizeof(reasonBuffer), 0);

		if (WinHttpWebSocketQueryCloseStatus(m_WebSocket, &status, reasonBuffer, ARRAYSIZE(reasonBuffer), &reasonLength) != ERROR_SUCCESS)
		{
			std::cerr << "[HyperDiscord] Error " << GetLastError() << " in WinHttpWebSocketQueryCloseStatus." << std::endl;
			exit(-1);
		}

		if (status != 1000)
			std::cout << "[HyperDiscord] The server closed the connection with status code: '" << status << "' and reason: '" << reasonBuffer << "'" << std::endl;

		WinHttpCloseHandle(m_WebSocket);
		WinHttpCloseHandle(m_Connection);
		WinHttpCloseHandle(m_Session);
	}

	std::wstring ConvertFromString(const std::string& string)
	{
		int length;
		int slength = (int)string.length() + 1;
		length = MultiByteToWideChar(CP_ACP, 0, string.c_str(), slength, 0, 0);
		wchar_t* buffer = new wchar_t[length];
		MultiByteToWideChar(CP_ACP, 0, string.c_str(), slength, buffer, length);
		std::wstring wstring(buffer);
		delete[] buffer;
		return wstring;
	}

	const std::string WebSocketClient::Listen()
	{
		BYTE outBuffer[1024];
		BYTE* outBufferPtr = outBuffer;
		DWORD outBufferLength = sizeof(outBuffer);
		DWORD bytesTransfered = 0;
		WINHTTP_WEB_SOCKET_BUFFER_TYPE bufferType;

		std::string output = "";

		std::fill(outBuffer, outBuffer + outBufferLength, 0);

		do
		{
			outBuffer[outBufferLength - 1] = '\0';
			output += std::string((char*)outBuffer);

			outBufferLength = sizeof(outBuffer);
			std::fill(outBuffer, outBuffer + outBufferLength, 0);
			outBufferPtr = outBuffer;
			bytesTransfered = 0;

			DWORD error = WinHttpWebSocketReceive(m_WebSocket, outBufferPtr, outBufferLength - 1, &bytesTransfered, &bufferType);
			if (error != ERROR_SUCCESS)
			{
				std::cerr << "[HyperDiscord] Error " << error << " in WinHttpWebSocketReceive." << std::endl;
				exit(-1);
			}

		} while (bufferType == WINHTTP_WEB_SOCKET_UTF8_FRAGMENT_BUFFER_TYPE);

		if (bufferType == WINHTTP_WEB_SOCKET_CLOSE_BUFFER_TYPE)
		{
			if (WinHttpWebSocketClose(m_WebSocket, WINHTTP_WEB_SOCKET_SUCCESS_CLOSE_STATUS, nullptr, 0) != ERROR_SUCCESS)
			{
				std::cerr << "[HyperDiscord] Error " << GetLastError() << " in WinHttpWebSocketClose." << std::endl;
				exit(-1);
			}

			USHORT status = 0;
			BYTE reasonBuffer[123];
			DWORD reasonLength;
			std::fill(reasonBuffer, reasonBuffer + sizeof(reasonBuffer), 0);

			if (WinHttpWebSocketQueryCloseStatus(m_WebSocket, &status, reasonBuffer, ARRAYSIZE(reasonBuffer), &reasonLength) != ERROR_SUCCESS)
			{
				std::cerr << "[HyperDiscord] Error " << GetLastError() << " in WinHttpWebSocketQueryCloseStatus." << std::endl;
				exit(-1);
			}

			std::cerr << "[HyperDiscord] The server closed the connection with status code: '" << status << "' and reason: '" << reasonBuffer << "'" << std::endl;
			exit(0);
		}

		output += std::string((char*)outBuffer);

		if (bufferType != WINHTTP_WEB_SOCKET_UTF8_MESSAGE_BUFFER_TYPE)
		{
			std::cerr << "[HyperDiscord] Unexpected buffer type." << std::endl;
			exit(-1);
		}

		if (nlohmann::json::parse(output)["op"] != 0)
			m_LastRealMessage = output;

		return output;
	}

	const std::string WebSocketClient::SendData(const std::string& message)
	{
		DWORD error;
		error = WinHttpWebSocketSend(m_WebSocket, WINHTTP_WEB_SOCKET_UTF8_MESSAGE_BUFFER_TYPE, message.empty() ? nullptr : (void*)message.data(), message.empty() ? 0 : message.length());
		if (error != ERROR_SUCCESS)
		{
			std::cerr << "[HyperDiscord] Error " << error << " in WinHttpWebSocketSend." << std::endl;
			exit(-1);
		}

		std::string copyMessage = "";

		do
		{
			copyMessage = m_LastRealMessage;
		} while (m_LastRealMessage == "");

		m_LastRealMessage = "";

		return copyMessage;
	}
}
