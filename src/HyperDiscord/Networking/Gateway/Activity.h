#pragma once

#ifndef _WIN32
#error HyperDiscord is only supporting Windows in the moment
#endif

#include <string>

#include "ActivityTimestamp.h"
#include "ActivityAssets.h"
#include "ActivityEmoji.h"
#include "ActivityParty.h"
#include "ActivitySecrets.h"
#include "Objects/Snowflake.h"

namespace HyperDiscord
{
	/* https://discord.com/developers/docs/topics/gateway#activity-object-activity-types */
	enum class ActivityType
	{
		GAME = 0,
		STREAMING,
		LISTENING,
		CUSTOM,
		COMPETING
	};

	/* https://discord.com/developers/docs/topics/gateway#activity-object-activity-flags */
	enum class ActivityFlags
	{
		INSTANCE = 1 << 0,
		JOIN = 1 << 1,
		SPECTATE = 1 << 2,
		JOIN_REQUEST = 1 << 3,
		SYNC = 1 << 4,
		PLAY = 1 << 5
	};

	/* https://discord.com/developers/docs/topics/gateway#activity-object-activity-structure */
	struct Activity
	{
		std::string Name;
		ActivityType Type;
		std::string Url;
		uint64_t CreatedAt;
		ActivityTimestamp Timestamps;
		Snowflake ApplicationId;
		std::string Details;
		std::string State;
		ActivityEmoji Emoji;
		ActivityParty Party;
		ActivityAssets Assets;
		ActivitySecrets Secrets;
		bool Instance;
		uint32_t Flags;

		friend std::ostream& operator<<(std::ostream& os, const Activity& activity);
	};

	inline std::ostream& operator<<(std::ostream& os, const ActivityType& activityType)
	{
		switch (activityType)
		{
		case ActivityType::GAME:
			os << "Game";
			break;
		case ActivityType::STREAMING:
			os << "Streaming";
			break;
		case ActivityType::LISTENING:
			os << "Listening";
			break;
		case ActivityType::CUSTOM:
			os << "Custom";
			break;
		case ActivityType::COMPETING:
			os << "Competing";
			break;
		}
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const Activity& activity)
	{
		os << "Name: " << activity.Name
			<< ", Type: " << activity.Type
			<< ", Url: " << activity.Url
			<< ", Created At: " << activity.CreatedAt
			<< ", Timestamps: " << activity.Timestamps
			<< ", Application Id: " << activity.ApplicationId
			<< ", Details: " << activity.Details
			<< ", State: " << activity.State
			<< ", Emoji: " << activity.Emoji
			<< ", Party: " << activity.Party
			<< ", Assets: " << activity.Assets
			<< ", Secrets: " << activity.Secrets
			<< ", Instance: " << activity.Instance
			<< ", Flags: " << activity.Flags;
		return os;
	}
}
