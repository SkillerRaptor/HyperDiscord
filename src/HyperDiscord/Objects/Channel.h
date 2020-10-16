#pragma once

#include <string>
#include <vector>

#include "Overwrite.h"
#include "Snowflake.h"
#include "User.h"
#include "Utilities/Iso8601.h"

enum ChannelType
{
	GUILD_TEXT = 0,
	DM,
	GUILD_VOICE,
	GROUP_DM,
	GUILD_CATEGORY,
	GUILD_NEWS,
	GUILD_STORE
};

/* https://discord.com/developers/docs/resources/channel#channel-object-channel-structure */
class Channel
{
private:
	Snowflake m_Id;
	ChannelType m_Type;
	Snowflake m_GuildId;
	uint32_t m_Position;
	std::vector<Overwrite> m_PermissionOverwrites;
	std::string m_Name;
	std::string m_Topic;
	bool m_Nsfw;
	Snowflake m_LastMessageId;
	uint32_t m_Bitrate;
	uint32_t m_UserLimit;
	uint32_t m_RateLimitPerUser;
	std::vector<User> m_Recipients;
	std::string m_Icon;
	Snowflake m_OwnerId;
	Snowflake m_ApplicationId;
	Snowflake m_ParentId;
	Iso8601 m_LastPinTimestamp;

public:
	Channel(Snowflake id, ChannelType type, Snowflake guildId, uint32_t position, const std::vector<Overwrite>& permissionOverwrites, const std::string& name, const std::string& topic, bool nsfw, Snowflake lastMessageId, uint32_t bitrate, uint32_t userLimit, uint32_t rateLimitPerUser, const std::vector<User>& recipients, const std::string& icon, Snowflake ownerId, Snowflake applicationId, Snowflake parentId, Iso8601 lastPinTimestamp);

	void SetId(Snowflake id);
	Snowflake GetId() const;

	void SetType(ChannelType type);
	ChannelType GetType() const;

	void SetGuildId(Snowflake guildId);
	Snowflake GetGuildId() const;

	void SetPosition(uint32_t position);
	uint32_t GetPosition() const;

	void SetPermissionOverwrites(const std::vector<Overwrite>& permissionOverwrites);
	std::vector<Overwrite> GetPermissionOverwrites() const;

	void SetName(const std::string& name);
	std::string GetName() const;

	void SetTopic(const std::string& topic);
	std::string GetTopic() const;

	void SetNsfw(bool nsfw);
	bool GetNsfw() const;

	void SetLastMessageId(Snowflake lastMessageId);
	Snowflake GetLastMessageId() const;

	void SetBitrate(uint32_t bitrate);
	uint32_t GetBitrate() const;

	void SetUserLimit(uint32_t userLimit);
	uint32_t GetUserLimit() const;

	void SetRateLimitPerUser(uint32_t rateLimitPerUser);
	uint32_t GetRateLimitPerUser() const;

	void SetRecipients(const std::vector<User>& recipients);
	std::vector<User> GetRecipients() const;

	void SetIcon(const std::string& icon);
	std::string GetIcon() const;

	void SetOwnerId(Snowflake ownerId);
	Snowflake GetOwnerId() const;

	void SetApplicationId(Snowflake applicationId);
	Snowflake GetApplicationId() const;

	void SetParentId(Snowflake parentId);
	Snowflake GetParentId() const;

	void SetLastPinTimestamp(Iso8601 lastPinTimestamp);
	Iso8601 GetLastPinTimestamp() const;
};
