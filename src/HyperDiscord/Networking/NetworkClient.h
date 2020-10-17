#pragma once

#define CPPHTTPLIB_OPENSSL_SUPPORT
#include <httplib.h>
#include <json.hpp>

#include "Core/Token.h"
#include "Objects/Channel.h"
#include "Objects/Snowflake.h"

namespace HyperDiscord
{
	class NetworkClient
	{
	private:
		Token m_Token;
		httplib::SSLClient* m_SSLClient;

	public:
		NetworkClient(Token token);
		~NetworkClient();

		Channel GetChannel(Snowflake channelId) const;

	private:
		nlohmann::json Get(const std::string& path) const;
		//nlohmann::json Post(const std::string& path);
		//nlohmann::json Patch(const std::string& path);
		//nlohmann::json Delete(const std::string& path);

		bool Contains(nlohmann::json json, const std::string& key) const;
	};
}
