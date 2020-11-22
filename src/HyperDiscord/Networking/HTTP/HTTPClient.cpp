#include "HTTPClient.hpp"

#include <iostream>

namespace HyperDiscord
{
	HTTPClient::HTTPClient()
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

		m_Connection = WinHttpConnect(m_Session, L"www.discord.com", INTERNET_DEFAULT_HTTPS_PORT, 0);
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

	HTTPResult HTTPClient::Get(const std::string& path)
	{
		HINTERNET request = WinHttpOpenRequest(m_Connection, L"GET", ConvertFromString(path).c_str(), nullptr, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, WINHTTP_FLAG_SECURE);
		
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

		LPVOID headerData = GetRequestHeaders(request);
		printf("%S", headerData);
		delete[] headerData;

		DWORD dataSize = 0;
		DWORD downloadedSize = 0;
		LPSTR outBuffer;

		do
		{
			dataSize = 0;
			if (!WinHttpQueryDataAvailable(request, &dataSize))
			{
				std::cerr << "[HyperDiscord] Error " << GetLastError() << " in WinHttpQueryDataAvailable." << std::endl;
				exit(-1);
			}

			outBuffer = new char[dataSize + 1];
			if (!outBuffer)
			{
				std::cerr << "[HyperDiscord] Out of memory." << std::endl;
				dataSize = 0;
				exit(-1);
			}

			ZeroMemory(outBuffer, dataSize + 1);
			if (!WinHttpReadData(request, (LPVOID)outBuffer, dataSize, &downloadedSize))
			{
				std::cerr << "[HyperDiscord] Error " << GetLastError() << " in WinHttpReadData." << std::endl;
				exit(-1);
			}
			std::cout << outBuffer << std::endl;
			delete[] outBuffer;
		} while (dataSize > 0);

		WinHttpCloseHandle(request);
		return HTTPResult(std::make_unique<HTTPResponse>(), HTTPResult::HTTPError::UNKNOWN);
	}

	HTTPResult HTTPClient::Get(const std::string& path, const Headers& headers)
	{
		HINTERNET request = WinHttpOpenRequest(m_Connection, L"GET", ConvertFromString(path).c_str(), nullptr, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, WINHTTP_FLAG_SECURE);
		if (!request)
		{
			std::cerr << "[HyperDiscord] Error " << GetLastError() << " in WinHttpOpenRequest." << std::endl;
			exit(-1);
		}

		std::wstring additionalHeaders;

		for (const auto& header : headers)
		{
			additionalHeaders += ConvertFromString(header.first);
			additionalHeaders += L": ";
			additionalHeaders += ConvertFromString(header.second);
			additionalHeaders += L"\r\n";
		}

		std::wcout << additionalHeaders << std::endl;

		if (!WinHttpSendRequest(request, additionalHeaders.c_str(), -1L, WINHTTP_NO_REQUEST_DATA, 0, 0, 0))
		{
			std::cerr << "[HyperDiscord] Error " << GetLastError() << " in WinHttpSendRequest." << std::endl;
			exit(-1);
		}

		if (!WinHttpReceiveResponse(request, nullptr))
		{
			std::cerr << "[HyperDiscord] Error " << GetLastError() << " in WinHttpReceiveResponse." << std::endl;
			exit(-1);
		}

		LPVOID headerData = GetRequestHeaders(request);
		printf("%S", headerData);
		delete[] headerData;

		DWORD dataSize = 0;
		DWORD downloadedSize = 0;
		LPSTR outBuffer;

		do
		{
			dataSize = 0;
			if (!WinHttpQueryDataAvailable(request, &dataSize))
			{
				std::cerr << "[HyperDiscord] Error " << GetLastError() << " in WinHttpQueryDataAvailable." << std::endl;
				exit(-1);
			}

			outBuffer = new char[dataSize + 1];
			if (!outBuffer)
			{
				std::cerr << "[HyperDiscord] Out of memory." << std::endl;
				dataSize = 0;
				exit(-1);
			}

			ZeroMemory(outBuffer, dataSize + 1);
			if (!WinHttpReadData(request, (LPVOID)outBuffer, dataSize, &downloadedSize))
			{
				std::cerr << "[HyperDiscord] Error " << GetLastError() << " in WinHttpReadData." << std::endl;
				exit(-1);
			}
			std::cout << outBuffer << std::endl;
			delete[] outBuffer;
		} while (dataSize > 0);

		WinHttpCloseHandle(request);
		return HTTPResult(std::make_unique<HTTPResponse>(), HTTPResult::HTTPError::UNKNOWN);
	}

	HTTPResult HTTPClient::Post(const std::string& path)
	{
		return HTTPResult(std::make_unique<HTTPResponse>(), HTTPResult::HTTPError::UNKNOWN);
	}

	HTTPResult HTTPClient::Post(const std::string& path, const std::string& body, const std::string& contentType)
	{
		return HTTPResult(std::make_unique<HTTPResponse>(), HTTPResult::HTTPError::UNKNOWN);
	}

	HTTPResult HTTPClient::Post(const std::string& path, const Headers& headers, const std::string& body, const std::string& contentType)
	{
		return HTTPResult(std::make_unique<HTTPResponse>(), HTTPResult::HTTPError::UNKNOWN);
	}

	HTTPResult HTTPClient::Put(const std::string& path)
	{
		return HTTPResult(std::make_unique<HTTPResponse>(), HTTPResult::HTTPError::UNKNOWN);
	}

	HTTPResult HTTPClient::Put(const std::string& path, const std::string& body, const std::string& contentType)
	{
		return HTTPResult(std::make_unique<HTTPResponse>(), HTTPResult::HTTPError::UNKNOWN);
	}

	HTTPResult HTTPClient::Put(const std::string& path, const Headers& headers, const std::string& body, const std::string& contentType)
	{
		return HTTPResult(std::make_unique<HTTPResponse>(), HTTPResult::HTTPError::UNKNOWN);
	}

	HTTPResult HTTPClient::Delete(const std::string& path)
	{
		return HTTPResult(std::make_unique<HTTPResponse>(), HTTPResult::HTTPError::UNKNOWN);
	}

	HTTPResult HTTPClient::Delete(const std::string& path, const std::string& body, const std::string& contentType)
	{
		return HTTPResult(std::make_unique<HTTPResponse>(), HTTPResult::HTTPError::UNKNOWN);
	}

	HTTPResult HTTPClient::Delete(const std::string& path, const Headers& headers, const std::string& body, const std::string& contentType)
	{
		return HTTPResult(std::make_unique<HTTPResponse>(), HTTPResult::HTTPError::UNKNOWN);
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

	const std::string HTTPClient::GenerateRequestString(const std::string& requestType, const std::string& path)
	{
		std::string request;
		request += requestType + " " + path + " HTTP/1.1\r\n";
		request += "Host: www.discord.com\r\n";
		request += "User-Agent: Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/53.0.2785.143 Safari/537.36\r\n";
		request += "\r\n";
		return request;
	}
}
