#include "NetworkClient.h"

namespace HyperDiscord
{
	NetworkClient::NetworkClient(Token token)
		: m_Token(token)
	{
	}

	NetworkClient::~NetworkClient()
	{
	}

	Channel NetworkClient::GetChannel(Snowflake channelId) const
	{
		std::stringstream ss;
		ss << "/channels/" << channelId;

		nlohmann::json channel = Get(ss.str());

		Channel channelStruct{};

		Snowflake id = Snowflake(std::stoll((std::string) channel.at("id")));
		ChannelType type = ChannelType((uint32_t) channel.at("type"));

		if(Check(channel, "guild_id")) channelStruct.GuildId = Snowflake(std::stoll((std::string) channel.at("guild_id")));

		if (Check(channel, "position")) channelStruct.Position = (uint32_t) channel.at("position");

		// TODO: Adding Permission Overwrites

		if (Check(channel, "name")) channelStruct.Name = (std::string) channel.at("name");

		if (Check(channel, "topic")) channelStruct.Name = (std::string) channel.at("topic");

		if (Check(channel, "nsfw")) channelStruct.Nsfw = (bool) channel.at("nsfw");

		if (Check(channel, "last_message_id")) channelStruct.LastMessageId = Snowflake(std::stoll((std::string) channel.at("last_message_id")));

		if (Check(channel, "bitrate")) channelStruct.Bitrate = (uint32_t) channel.at("bitrate");

		if (Check(channel, "user_limit")) channelStruct.UserLimit = (uint32_t) channel.at("user_limit");

		if (Check(channel, "rate_limit_per_user")) channelStruct.RateLimitPerUser = (uint32_t) channel.at("rate_limit_per_user");

		// TODO: Adding Recipients

		if (Check(channel, "icon")) channelStruct.Icon = (std::string) channel.at("icon");

		if (Check(channel, "ownerId")) channelStruct.LastMessageId = Snowflake(std::stoll((std::string) channel.at("owner_id")));

		if (Check(channel, "applicationId")) channelStruct.LastMessageId = Snowflake(std::stoll((std::string) channel.at("application_id")));

		if (Check(channel, "parentId")) channelStruct.LastMessageId = Snowflake(std::stoll((std::string) channel.at("parent_id")));

		// TODO: Adding Last Pin Timestamp

		return channelStruct;
	}

	nlohmann::json NetworkClient::Get(const std::string& path) const
	{
		std::stringstream ss;
		ss << "/api/v8" << path;

		return nlohmann::json::parse("");
	}

	bool NetworkClient::Check(nlohmann::json json, const std::string& key) const
	{
		return Contains(json, key) && !IsNull(json, key);
	}

	bool NetworkClient::Contains(nlohmann::json json, const std::string& key) const
	{
		return json.find(key) != json.end();
	}

	bool NetworkClient::IsNull(nlohmann::json json, const std::string& key) const
	{
		return json.at(key).is_null();
	}
}
