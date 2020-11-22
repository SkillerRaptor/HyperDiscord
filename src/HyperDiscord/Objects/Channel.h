#pragma once

#ifndef _WIN32
#error HyperDiscord is only supporting Windows in the moment
#endif

#include <iostream>
#include <string>
#include <vector>

#include "Overwrite.h"
#include "Snowflake.h"
#include "User.h"
#include "Utilities/Iso8601.h"

namespace HyperDiscord
{
	/* https://discord.com/developers/docs/resources/channel#channel-object-channel-types */
	enum class ChannelType
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
	struct Channel
	{
		Snowflake Id;
		ChannelType Type;
		Snowflake GuildId;
		uint16_t Position;
		std::vector<Overwrite> PermissionOverwrites;
		std::string Name;
		std::string Topic;
		bool Nsfw;
		Snowflake LastMessageId;
		uint32_t Bitrate;
		uint32_t UserLimit;
		uint32_t RateLimitPerUser;
		std::vector<User> Recipients;
		std::string Icon;
		Snowflake OwnerId;
		Snowflake ApplicationId;
		Snowflake ParentId;
		Iso8601 LastPinTimestamp;

		friend std::ostream& operator<<(std::ostream& os, const Channel& channel);
	};

	inline std::ostream& operator<<(std::ostream& os, const ChannelType& channelType)
	{
		switch (channelType)
		{
		case ChannelType::GUILD_TEXT:
			os << "Guild Text";
			break;
		case ChannelType::DM:
			os << "Guild Direct Message";
			break;
		case ChannelType::GUILD_VOICE:
			os << "Guild Voice";
			break;
		case ChannelType::GROUP_DM:
			os << "Group Direct Message";
			break;
		case ChannelType::GUILD_CATEGORY:
			os << "Guild Category";
			break;
		case ChannelType::GUILD_NEWS:
			os << "Guild News";
			break;
		case ChannelType::GUILD_STORE:
			os << "Guild Store";
			break;
		}
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const Channel& channel)
	{
		os << "Id: " << channel.Id
			<< ", Type: " << channel.Type
			<< ", Guild Id: " << channel.GuildId
			<< ", Position: " << channel.Position
			//<< ", Permission Overwrites: " << channel.PermissionOverwrites
			<< ", Name: " << channel.Name
			<< ", Topic: " << channel.Topic
			<< ", Nsfw: " << channel.Nsfw
			<< ", Last Message Id: " << channel.LastMessageId
			<< ", Bitrate: " << channel.Bitrate
			<< ", User Limit: " << channel.UserLimit
			<< ", Rate Limit Per User: " << channel.RateLimitPerUser
			//<< ", Recipients: " << channel.Recipients
			<< ", Icon: " << channel.Icon
			<< ", Owner Id: " << channel.OwnerId
			<< ", Application Id: " << channel.ApplicationId
			<< ", Parent Id: " << channel.ParentId;
			//<< ", Last Pin Timestamp: " << channel.LastPinTimestamp;
		return os;
	}
}
