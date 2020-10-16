#include "Channel.h"

Channel::Channel(Snowflake id, ChannelType type, Snowflake guildId, uint32_t position, const std::vector<Overwrite>& permissionOverwrites, const std::string& name, const std::string& topic, bool nsfw, Snowflake lastMessageId, uint32_t bitrate, uint32_t userLimit, uint32_t rateLimitPerUser, const std::vector<User>& recipients, const std::string& icon, Snowflake ownerId, Snowflake applicationId, Snowflake parentId, Iso8601 lastPinTimestamp)
	: m_Id(id), m_Type(type), m_GuildId(guildId), m_Position(position), m_PermissionOverwrites(permissionOverwrites), m_Name(name), m_Topic(topic), m_Nsfw(nsfw), m_LastMessageId(lastMessageId), m_Bitrate(bitrate), m_UserLimit(userLimit), m_RateLimitPerUser(rateLimitPerUser), m_Recipients(recipients), m_Icon(icon), m_OwnerId(ownerId), m_ApplicationId(applicationId), m_ParentId(parentId), m_LastPinTimestamp(lastPinTimestamp)

{
}

void Channel::SetId(Snowflake id)
{
	m_Id = id;
}

Snowflake Channel::GetId() const
{
	return m_Id;
};

void Channel::SetType(ChannelType type)
{
	m_Type = type;
}

ChannelType Channel::GetType() const
{
	return m_Type;
};

void Channel::SetGuildId(Snowflake guildId)
{
	m_GuildId = guildId;
}

Snowflake Channel::GetGuildId() const
{
	return m_GuildId;
};

void Channel::SetPosition(uint32_t position)
{
	m_Position = position;
}

uint32_t Channel::GetPosition() const
{
	return m_Position;
};

void Channel::SetPermissionOverwrites(const std::vector<Overwrite>& permissionOverwrites)
{
	m_PermissionOverwrites = permissionOverwrites;
}

std::vector<Overwrite> Channel::GetPermissionOverwrites() const
{
	return m_PermissionOverwrites;
};

void Channel::SetName(const std::string& name)
{
	m_Name = name;
}

std::string Channel::GetName() const
{
	return m_Name;
};

void Channel::SetTopic(const std::string& topic)
{
	m_Topic = topic;
}

std::string Channel::GetTopic() const
{
	return m_Topic;
};

void Channel::SetNsfw(bool nsfw)
{
	m_Nsfw = nsfw;
}

bool Channel::GetNsfw() const
{
	return m_Nsfw;
};

void Channel::SetLastMessageId(Snowflake lastMessageId)
{
	m_LastMessageId = lastMessageId;
}

Snowflake Channel::GetLastMessageId() const
{
	return m_LastMessageId;
};

void Channel::SetBitrate(uint32_t bitrate)
{
	m_Bitrate = bitrate;
}

uint32_t Channel::GetBitrate() const
{
	return m_Bitrate;
};

void Channel::SetUserLimit(uint32_t userLimit)
{
	m_UserLimit = userLimit;
}

uint32_t Channel::GetUserLimit() const
{
	return m_UserLimit;
};

void Channel::SetRateLimitPerUser(uint32_t rateLimitPerUser)
{
	m_RateLimitPerUser = rateLimitPerUser;
}

uint32_t Channel::GetRateLimitPerUser() const
{
	return m_RateLimitPerUser;
}

void Channel::SetRecipients(const std::vector<User>& recipients)
{
	m_Recipients = recipients;
}

std::vector<User> Channel::GetRecipients() const
{
	return m_Recipients;
};

void Channel::SetIcon(const std::string& icon)
{
	m_Icon = icon;
}

std::string Channel::GetIcon() const
{
	return m_Icon;
};

void Channel::SetOwnerId(Snowflake ownerId)
{
	m_OwnerId = ownerId;
}

Snowflake Channel::GetOwnerId() const
{
	return m_OwnerId;
};

void Channel::SetApplicationId(Snowflake applicationId)
{
	m_ApplicationId = applicationId;
}

Snowflake Channel::GetApplicationId() const
{
	return m_ApplicationId;
};

void Channel::SetParentId(Snowflake parentId)
{
	m_ParentId = parentId;
}

Snowflake Channel::GetParentId() const
{
	return m_ParentId;
};

void Channel::SetLastPinTimestamp(Iso8601 lastPinTimestamp)
{
	m_LastPinTimestamp = lastPinTimestamp;
}

Iso8601 Channel::GetLastPinTimestamp() const
{
	return m_LastPinTimestamp;
};
