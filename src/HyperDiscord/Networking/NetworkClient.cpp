#include "NetworkClient.h"

namespace HyperDiscord
{
	NetworkClient::NetworkClient(Token token)
		: m_Token(token)
	{
		m_SSLClient = new httplib::SSLClient("discord.com");
		m_SSLClient->set_default_headers({{ "Authorization", token.GetAuthorization() }});
		m_SSLClient->set_keep_alive(true);
	}

	NetworkClient::~NetworkClient()
	{
		m_SSLClient->set_keep_alive(false);
	}

	Channel NetworkClient::GetChannel(Snowflake channelId) const
	{
		std::stringstream ss;
		ss << "/channels/" << channelId;

		nlohmann::json channel = Get(ss.str());

		Snowflake id = Snowflake(std::stoll((std::string) channel.at("id")));
		ChannelType type = ChannelType((uint32_t) channel.at("type"));

		Snowflake guildId = Snowflake();
		if(Contains(channel, "guild_id")) guildId = Snowflake(std::stoll((std::string) channel.at("guild_id")));

		uint32_t position = -1;
		if (Contains(channel, "position")) position = (uint32_t) channel.at("position");

		// TODO: Adding Permission Overwrites

		std::string name = "";
		if (Contains(channel, "name")) name = (std::string) channel.at("name");

		std::string topic = "";
		if (Contains(channel, "topic")) name = (std::string) channel.at("topic");

		bool nsfw = false;
		if (Contains(channel, "nsfw")) nsfw = (bool) channel.at("nsfw");

		Snowflake lastMessageId = Snowflake();
		if (Contains(channel, "last_message_id")) lastMessageId = Snowflake(std::stoll((std::string) channel.at("last_message_id")));

		uint32_t bitrate = -1;
		if (Contains(channel, "bitrate")) bitrate = (uint32_t) channel.at("bitrate");

		uint32_t userLimit = -1;
		if (Contains(channel, "user_limit")) userLimit = (uint32_t) channel.at("user_limit");

		uint32_t rateLimitPerUser = -1;
		if (Contains(channel, "rate_limit_per_user")) rateLimitPerUser = (uint32_t) channel.at("rate_limit_per_user");

		// TODO: Adding Recipients

		std::string icon = "";
		if (Contains(channel, "icon")) icon = (std::string) channel.at("icon");

		Snowflake ownerId = Snowflake();
		if (Contains(channel, "ownerId")) lastMessageId = Snowflake(std::stoll((std::string) channel.at("owner_id")));

		Snowflake applicationId = Snowflake();
		if (Contains(channel, "applicationId")) lastMessageId = Snowflake(std::stoll((std::string) channel.at("application_id")));

		Snowflake parentId = Snowflake();
		if (Contains(channel, "parentId")) lastMessageId = Snowflake(std::stoll((std::string) channel.at("parent_id")));

		// TODO: Adding Last Pin Timestamp

		return Channel(id, type, guildId, 0, {}, name, topic, nsfw, lastMessageId, bitrate, userLimit, rateLimitPerUser, {}, icon, ownerId, applicationId, parentId, Iso8601(""));
	}

	nlohmann::json NetworkClient::Get(const std::string& path) const
	{
		std::stringstream ss;
		ss << "/api/v8" << path;

		httplib::Result result = m_SSLClient->Get(ss.str().c_str());
		return nlohmann::json::parse(result->body);
	}

	bool NetworkClient::Contains(nlohmann::json json, const std::string& key) const
	{
		return json.find(key) != json.end();
	}
}
