#pragma once

#include <json.hpp>

#include <sstream>

#include "Core/Token.h"
#include "Objects/Channel.h"
#include "Objects/Snowflake.h"

namespace HyperDiscord
{
	class NetworkClient
	{
	private:
		Token m_Token;

	public:
		NetworkClient(Token token);
		~NetworkClient();

		Channel GetChannel(Snowflake channelId) const;

	private:
		nlohmann::json Get(const std::string& path) const;
		//nlohmann::json Post(const std::string& path);
		//nlohmann::json Patch(const std::string& path);
		//nlohmann::json Delete(const std::string& path);

		bool Check(nlohmann::json json, const std::string& key) const;
		bool Contains(nlohmann::json json, const std::string& key) const;
		bool IsNull(nlohmann::json json, const std::string& key) const;
	};
}
