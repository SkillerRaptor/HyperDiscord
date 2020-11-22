#pragma once

#include <memory>

#include "HTTPResponse.hpp"

namespace HyperDiscord
{
	class HTTPResult
	{
	public:
		enum class HTTPError
		{
			SUCCESS,
			UNKNOWN,
			CONNECTION,
			BINDIPADDRESS,
			READ,
			WRITE,
			EXCEEDREDIRECTCOUNT,
			CANCELED,
			SSLCONNECTION,
			SSLLOADINGCERTS,
			SSLSERVERVERIFICATION,
			UNSUPPORTEDMULTIPARTBOUNDARYCHARS
		};

	private:
		std::unique_ptr<HTTPResponse> m_Response;
		HTTPError m_Error;

	public:
		HTTPResult(std::unique_ptr<HTTPResponse> response, HTTPError error);

		HTTPError GetError() const;

		const HTTPResponse GetResponse() const;
		HTTPResponse GetResponse();

		const HTTPResponse& operator*() const;
		HTTPResponse& operator*();

		const HTTPResponse* operator->() const;
		HTTPResponse* operator->();

		operator bool() const;

		bool operator==(nullptr_t) const;
		bool operator!=(nullptr_t) const;
	};
}
