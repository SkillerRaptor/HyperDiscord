#pragma once

#ifndef _WIN32
#error HyperDiscord is only supporting Windows in the moment
#endif

#include <Windows.h>
#include <winhttp.h>

#include <string>
#include <vector>

#include "Core/Token.h"

namespace HyperDiscord
{
	using Headers = std::vector<std::pair<std::string, std::string>>;

	class HTTPClient
	{
	private:
		Token m_Token;
		
		HINTERNET m_Session;
		HINTERNET m_Connection;

	public:
		HTTPClient(Token token);
		~HTTPClient();

		const std::string Get(const std::string& path);
		const std::string Get(const std::string& path, const Headers& headers);

		const std::string Post(const std::string& path);
		const std::string Post(const std::string& path, const std::string& body);
		const std::string Post(const std::string& path, const Headers& headers, const std::string& body);

		const std::string Put(const std::string& path);
		const std::string Put(const std::string& path, const std::string& body);
		const std::string Put(const std::string& path, const Headers& headers, const std::string& body);

		const std::string Patch(const std::string& path);
		const std::string Patch(const std::string& path, const std::string& body);
		const std::string Patch(const std::string& path, const Headers& headers, const std::string& body);

		const std::string Delete(const std::string& path);
		const std::string Delete(const std::string& path, const std::string& body);
		const std::string Delete(const std::string& path, const Headers& headers, const std::string& body);

	private:
		void Init();
		void Shutdown();

		HINTERNET GenerateRequest(const std::string& path, const std::string& requestString, const Headers& headers, const std::string& body);
		const std::string GetResponse(HINTERNET request);
		const std::string GetResponseHeader(HINTERNET request);
		LPVOID GetRequestHeaders(HINTERNET request);
		const std::wstring GenerateHeaders(Headers headers);
		std::wstring ConvertFromString(const std::string& string);
	};
}
