#include "HTTPClient.h"

#include <algorithm>
#include <iostream>

namespace HyperDiscord
{
	HTTPClient::HTTPClient(Token token)
		: m_Token(token)
	{
		Init();
	}

	HTTPClient::~HTTPClient()
	{
		Shutdown();
	}

	void HTTPClient::Init()
	{
		m_Session = WinHttpOpen(L"HyperDiscord", WINHTTP_ACCESS_TYPE_AUTOMATIC_PROXY, WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
		if (!m_Session)
		{
			std::cerr << "[HyperDiscord] Error " << GetLastError() << " in WinHttpOpen." << std::endl;
			exit(-1);
		}

		m_Connection = WinHttpConnect(m_Session, L"discord.com", INTERNET_DEFAULT_HTTPS_PORT, 0);
		if (!m_Connection)
		{
			std::cerr << "[HyperDiscord] Error " << GetLastError() << " in WinHttpConnect." << std::endl;
			exit(-1);
		}
	}

	void HTTPClient::Shutdown()
	{
		WinHttpCloseHandle(m_Connection);
		WinHttpCloseHandle(m_Session);
	}

	const std::string HTTPClient::Get(const std::string& path)
	{
		HINTERNET request = GenerateRequest(path, "GET", {}, "");
		const std::string response = GetResponseHeader(request);
		WinHttpCloseHandle(request);
		return response;
	}

	const std::string HTTPClient::Get(const std::string& path, const Headers& headers)
	{
		HINTERNET request = GenerateRequest(path, "GET", headers, "");
		const std::string response = GetResponseHeader(request);
		WinHttpCloseHandle(request);
		return response;
	}

	const std::string HTTPClient::Post(const std::string& path)
	{
		HINTERNET request = GenerateRequest(path, "POST", {}, "");
		const std::string response = GetResponseHeader(request);
		WinHttpCloseHandle(request);
		return response;
	}

	const std::string HTTPClient::Post(const std::string& path, const std::string& body)
	{
		HINTERNET request = GenerateRequest(path, "POST", {}, body);
		const std::string response = GetResponseHeader(request);
		WinHttpCloseHandle(request);
		return response;
	}

	const std::string HTTPClient::Post(const std::string& path, const Headers& headers, const std::string& body)
	{
		HINTERNET request = GenerateRequest(path, "POST", headers, "");
		const std::string response = GetResponseHeader(request);
		WinHttpCloseHandle(request);
		return response;
	}

	const std::string HTTPClient::Put(const std::string& path)
	{
		HINTERNET request = GenerateRequest(path, "PUT", {}, "");
		const std::string response = GetResponseHeader(request);
		WinHttpCloseHandle(request);
		return response;
	}

	const std::string HTTPClient::Put(const std::string& path, const std::string& body)
	{
		HINTERNET request = GenerateRequest(path, "PUT", {}, body);
		const std::string response = GetResponseHeader(request);
		WinHttpCloseHandle(request);
		return response;
	}

	const std::string HTTPClient::Put(const std::string& path, const Headers& headers, const std::string& body)
	{
		HINTERNET request = GenerateRequest(path, "PUT", headers, body);
		const std::string response = GetResponseHeader(request);
		WinHttpCloseHandle(request);
		return response;
	}

	const std::string HTTPClient::Patch(const std::string& path)
	{
		HINTERNET request = GenerateRequest(path, "PATCH", {}, "");
		const std::string response = GetResponseHeader(request);
		WinHttpCloseHandle(request);
		return response;
	}

	const std::string HTTPClient::Patch(const std::string& path, const std::string& body)
	{
		HINTERNET request = GenerateRequest(path, "PATCH", {}, body);
		const std::string response = GetResponseHeader(request);
		WinHttpCloseHandle(request);
		return response;
	}

	const std::string HTTPClient::Patch(const std::string& path, const Headers& headers, const std::string& body)
	{
		HINTERNET request = GenerateRequest(path, "PATCH", headers, "");
		const std::string response = GetResponseHeader(request);
		WinHttpCloseHandle(request);
		return response;
	}

	const std::string HTTPClient::Delete(const std::string& path)
	{
		HINTERNET request = GenerateRequest(path, "DELETE", {}, "");
		const std::string response = GetResponseHeader(request);
		WinHttpCloseHandle(request);
		return response;
	}

	const std::string HTTPClient::Delete(const std::string& path, const std::string& body)
	{
		HINTERNET request = GenerateRequest(path, "DELETE", {}, body);
		const std::string response = GetResponseHeader(request);
		WinHttpCloseHandle(request);
		return response;
	}

	const std::string HTTPClient::Delete(const std::string& path, const Headers& headers, const std::string& body)
	{
		HINTERNET request = GenerateRequest(path, "DELETE", headers, body);
		const std::string response = GetResponseHeader(request);
		WinHttpCloseHandle(request);
		return response;
	}

	HINTERNET HTTPClient::GenerateRequest(const std::string& path, const std::string& requestString, const Headers& headers, const std::string& body)
	{
		HINTERNET request = WinHttpOpenRequest(m_Connection, ConvertFromString(requestString).c_str(), ConvertFromString(path).c_str(), nullptr, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, WINHTTP_FLAG_SECURE);
		if (!request)
		{
			std::cerr << "[HyperDiscord] Error " << GetLastError() << " in WinHttpOpenRequest." << std::endl;
			exit(-1);
		}

		std::cout << requestString << std::endl;

		std::wstring additionalHeaders = GenerateHeaders(headers);
		if (!WinHttpSendRequest(request, additionalHeaders.c_str(), -1L, WINHTTP_NO_REQUEST_DATA, 0, (body == "") ? 0 : body.length(), 0))
		{
			std::cerr << "[HyperDiscord] Error " << GetLastError() << " in WinHttpSendRequest." << std::endl;
			exit(-1);
		}

		if (requestString == "POST")
		{
			DWORD dwBytesWritten = 0;
			WinHttpWriteData(request, (LPVOID)body.data(), strlen(body.c_str()), &dwBytesWritten);
		}

		if (!WinHttpReceiveResponse(request, nullptr))
		{
			std::cerr << "[HyperDiscord] Error " << GetLastError() << " in WinHttpReceiveResponse." << std::endl;
			exit(-1);
		}

		return request;
	}

	const std::string HTTPClient::GetResponse(HINTERNET request)
	{
		DWORD dataSize = 0;
		DWORD downloadedSize = 0;
		LPSTR outBuffer;

		std::string returnString;

		do
		{
			dataSize = 0;
			if (!WinHttpQueryDataAvailable(request, &dataSize))
			{
				std::cerr << "[HyperDiscord] Error " << GetLastError() << " in WinHttpQueryDataAvailable." << std::endl;
				exit(-1);
			}

			outBuffer = new char[dataSize + 1ULL];
			if (!outBuffer)
			{
				std::cerr << "[HyperDiscord] Out of memory." << std::endl;
				dataSize = 0;
				exit(-1);
			}

			ZeroMemory(outBuffer, dataSize + 1ULL);
			if (!WinHttpReadData(request, (LPVOID)outBuffer, dataSize, &downloadedSize))
			{
				std::cerr << "[HyperDiscord] Error " << GetLastError() << " in WinHttpReadData." << std::endl;
				exit(-1);
			}

			returnString += std::string(outBuffer);

			delete[] outBuffer;
		} while (dataSize > 0);

		return returnString;
	}

	const std::string HTTPClient::GetResponseHeader(HINTERNET request)
	{
		LPVOID headerData = GetRequestHeaders(request); // TODO: Adding HTTPResponse back with Header data
		const std::string responseBody = GetResponse(request);
		delete[] headerData;

		return responseBody;
	}

	LPVOID HTTPClient::GetRequestHeaders(HINTERNET request)
	{
		DWORD dataSize = 0;
		LPVOID outBuffer = nullptr;
		WinHttpQueryHeaders(request, WINHTTP_QUERY_RAW_HEADERS_CRLF, WINHTTP_HEADER_NAME_BY_INDEX, nullptr, &dataSize, WINHTTP_NO_HEADER_INDEX);

		if (GetLastError() == ERROR_INSUFFICIENT_BUFFER)
		{
			outBuffer = new WCHAR[dataSize / sizeof(WCHAR)];

			if (!WinHttpQueryHeaders(request, WINHTTP_QUERY_RAW_HEADERS_CRLF, WINHTTP_HEADER_NAME_BY_INDEX, outBuffer, &dataSize, WINHTTP_NO_HEADER_INDEX))
			{
				std::cerr << "[HyperDiscord] Error " << GetLastError() << " in WinHttpQueryHeaders." << std::endl;
				exit(-1);
			}
		}

		return outBuffer;
	}

	const std::wstring HTTPClient::GenerateHeaders(Headers headers)
	{
		std::wstring additionalHeaders;
		for (const auto& header : headers)
		{
			additionalHeaders += ConvertFromString(header.first);
			additionalHeaders += L": ";
			additionalHeaders += ConvertFromString(header.second);
			additionalHeaders += L"\r\n";
		}
		additionalHeaders += L"Authorization: ";
		additionalHeaders += ConvertFromString(m_Token.GetAuthorization());
		additionalHeaders += L"\r\n";
		additionalHeaders += L"Content-Type: application/json\r\n";
		return additionalHeaders;
	}

	std::wstring HTTPClient::ConvertFromString(const std::string& string)
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
}
