#pragma once

#include <string>
#include <vector>

namespace HyperDiscord
{
	using Headers = std::vector<std::pair<std::string, std::string>>;

	class HTTPResponse
	{
	private:
		std::string m_Method;
		std::string m_Path;
		Headers m_Headers;
		std::string m_Body;

	public:
		HTTPResponse(const std::string& method = "", const std::string& path = "", Headers headers = {}, const std::string& body = "");

		const std::string& GetMethod() const;
		const std::string& GetPath() const;
		const Headers& GetHeaders() const;
		const std::string& GetBody() const;
	};
}
