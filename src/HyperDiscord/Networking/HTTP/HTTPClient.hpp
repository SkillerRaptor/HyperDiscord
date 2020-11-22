#pragma once

#include <Windows.h>
#include <winhttp.h>

#include "HTTPResult.hpp"

namespace HyperDiscord
{
	class HTTPClient
	{
	private:
		HINTERNET m_Session;
		HINTERNET m_Connection;

	public:
		HTTPClient();
		~HTTPClient();

		HTTPResult Get(const std::string& path);
		HTTPResult Get(const std::string& path, const Headers& headers);

		HTTPResult Post(const std::string& path);
		HTTPResult Post(const std::string& path, const std::string& body, const std::string& contentType);
		HTTPResult Post(const std::string& path, const Headers& headers, const std::string& body, const std::string& contentType);

		HTTPResult Put(const std::string& path);
		HTTPResult Put(const std::string& path, const std::string& body, const std::string& contentType);
		HTTPResult Put(const std::string& path, const Headers& headers, const std::string& body, const std::string& contentType);

		HTTPResult Patch(const std::string& path);
		HTTPResult Patch(const std::string& path, const std::string& body, const std::string& contentType);
		HTTPResult Patch(const std::string& path, const Headers& headers, const std::string& body, const std::string& contentType);

		HTTPResult Delete(const std::string& path);
		HTTPResult Delete(const std::string& path, const std::string& body, const std::string& contentType);
		HTTPResult Delete(const std::string& path, const Headers& headers, const std::string& body, const std::string& contentType);

	private:
		void Init();
		void Shutdown();

		LPVOID GetRequestHeaders(HINTERNET request);
		std::wstring ConvertFromString(const std::string& string);
		const std::string GenerateRequestString(const std::string& requestType, const std::string& path);
	};
}
