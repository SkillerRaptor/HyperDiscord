#include "WebSocketClient.h"

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

		HINTERNET request = WinHttpOpenRequest(m_Connection, L"GET", L"", nullptr, 0, 0, 0);
		if (!request)
		{
			std::cerr << "[HyperDiscord] Error " << GetLastError() << " in WinHttpOpenRequest." << std::endl;
			exit(-1);
		}

		if (!WinHttpSetOption(request, WINHTTP_OPTION_UPGRADE_TO_WEB_SOCKET, 0, 0))
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

		std::cout << "[HyperDiscord] Websocket Initialized" << std::endl;
	}

	void WebSocketClient::Shutdown()
	{
		WinHttpCloseHandle(m_WebSocket);
		WinHttpCloseHandle(m_Connection);
		WinHttpCloseHandle(m_Session);
	}

	const std::string WebSocketClient::SendMessage(const std::string& path, const std::string& message)
	{
		if (WinHttpWebSocketSend(m_WebSocket, WINHTTP_WEB_SOCKET_UTF8_MESSAGE_BUFFER_TYPE, (PVOID)message.c_str(), message.length()) != ERROR_SUCCESS)
		{
			std::cerr << "[HyperDiscord] Error " << GetLastError() << " in WinHttpWebSocketSend." << std::endl;
			exit(-1);
		}

		BYTE outBuffer[1024];
		BYTE* outBufferPtr = outBuffer;
		DWORD outBufferLength = sizeof(outBuffer);
		DWORD bytesTransfered = 0;
		WINHTTP_WEB_SOCKET_BUFFER_TYPE bufferType;

		std::fill(outBuffer, outBuffer + outBufferLength, 0);

		do
		{
			if (outBufferLength == 0)
			{
				std::cerr << "[HyperDiscord] Not enough memory." << std::endl;
				exit(-1);
			}

			if (WinHttpWebSocketReceive(m_WebSocket, outBufferPtr, outBufferLength, &bytesTransfered, &bufferType) != ERROR_SUCCESS)
			{
				std::cerr << "[HyperDiscord] Error " << GetLastError() << " in WinHttpWebSocketReceive." << std::endl;
				exit(-1);
			}

			outBufferPtr += bytesTransfered;
			outBufferLength -= bytesTransfered;
		} while (bufferType == WINHTTP_WEB_SOCKET_UTF8_FRAGMENT_BUFFER_TYPE);

		if (bufferType != WINHTTP_WEB_SOCKET_UTF8_MESSAGE_BUFFER_TYPE)
		{
			std::cerr << "[HyperDiscord] Unexpected buffer type." << std::endl;
			exit(-1);
		}

		if (WinHttpWebSocketClose(m_WebSocket, WINHTTP_WEB_SOCKET_SUCCESS_CLOSE_STATUS, nullptr, 0) != ERROR_SUCCESS)
		{
			std::cerr << "[HyperDiscord] Error " << GetLastError() << " in WinHttpWebSocketClose." << std::endl;
			exit(-1);
		}

		return std::string((char*) outBuffer);
	}
}
