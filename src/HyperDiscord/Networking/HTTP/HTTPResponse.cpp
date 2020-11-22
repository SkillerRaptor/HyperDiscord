#include "HTTPResponse.hpp"

namespace HyperDiscord
{
	HTTPResponse::HTTPResponse(const std::string& method, const std::string& path, Headers headers, const std::string& body)
		: m_Method(method), m_Path(path), m_Headers(headers), m_Body(body)
	{
	}

	const std::string& HTTPResponse::GetMethod() const
	{
		return m_Method;
	}

	const std::string& HTTPResponse::GetPath() const
	{
		return m_Path;
	}

	const Headers& HTTPResponse::GetHeaders() const
	{
		return m_Headers;
	}

	const std::string& HTTPResponse::GetBody() const
	{
		return m_Body;
	}
}
