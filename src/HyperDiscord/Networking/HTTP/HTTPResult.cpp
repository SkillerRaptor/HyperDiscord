#include "HTTPResult.hpp"

namespace HyperDiscord
{
	HTTPResult::HTTPResult(std::unique_ptr<HTTPResponse> response, HTTPError error)
		: m_Response(std::move(response)), m_Error(error)
	{
	}

	HTTPResult::HTTPError HTTPResult::GetError() const
	{
		return m_Error;
	}

	const HTTPResponse HTTPResult::GetResponse() const
	{
		return *m_Response;
	}

	HTTPResponse HTTPResult::GetResponse()
	{
		return *m_Response;
	}

	const HTTPResponse& HTTPResult::operator*() const
	{
		return *m_Response;
	}

	HTTPResponse& HTTPResult::operator*()
	{
		return *m_Response;
	}

	const HTTPResponse* HTTPResult::operator->() const
	{
		return m_Response.get();
	}

	HTTPResponse* HTTPResult::operator->()
	{
		return m_Response.get();
	}

	HTTPResult::operator bool() const
	{
		return m_Response != nullptr;
	}

	bool HTTPResult::operator==(nullptr_t) const
	{
		return m_Response == nullptr;
	}

	bool HTTPResult::operator!=(nullptr_t) const
	{
		return m_Response != nullptr;
	}
}
