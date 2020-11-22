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
	class Activity
	{
	private:
		std::string m_Name;
		ActivityType m_Type;
		std::string m_Url;
		uint64_t m_CreatedAt;
		ActivityTimestamp m_Timestamps;
		Snowflake m_ApplicationId;
		std::string m_Details;
		std::string m_State;
		ActivityEmoji m_Emoji;
		ActivityParty m_Party;
		ActivityAssets m_Assets;
		ActivitySecrets m_Secrets;
		bool m_Instance;
		uint32_t m_Flags;

	public:
		Activity(const std::string& name, ActivityType type, const std::string& url, uint64_t createdAt, ActivityTimestamp timestamps, Snowflake applicationId, const std::string& details, const std::string& state, ActivityEmoji emoji, ActivityParty party, ActivityAssets assets, ActivitySecrets secrets, bool instance, uint32_t flags);

		void SetName(const std::string& name);
		const std::string& GetName() const;

		void SetType(ActivityType type);
		ActivityType GetType() const;

		void SetUrl(const std::string& url);
		const std::string& GetUrl() const;

		void SetCreatedAt(uint64_t createdAt);
		uint64_t GetCreatedAt() const;

		void SetTimestamps(ActivityTimestamp timestamps);
		ActivityTimestamp GetTimestamps() const;

		void SetApplicationId(Snowflake applicationId);
		Snowflake GetApplicationId() const;

		void SetDetails(const std::string& details);
		const std::string& GetDetails() const;

		void SetState(const std::string& state);
		const std::string& GetState() const;

		void SetEmoji(ActivityEmoji emoji);
		ActivityEmoji GetEmoji() const;

		void SetParty(ActivityParty party);
		ActivityParty GetParty() const;

		void SetAssets(ActivityAssets assets);
		ActivityAssets GetAssets() const;

		void SetSecrets(ActivitySecrets secrets);
		ActivitySecrets GetSecrets() const;

		void SetInstance(bool instance);
		bool IsInstance() const;

		void SetFlags(uint32_t flags);
		uint32_t GetFlags() const;

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
		os << "Name: " << activity.GetName()
			<< ", Type: " << activity.GetType()
			<< ", Url: " << activity.GetUrl()
			<< ", Created At: " << activity.GetCreatedAt()
			<< ", Timestamps: " << activity.GetTimestamps()
			<< ", Application Id: " << activity.GetApplicationId()
			<< ", Details: " << activity.GetDetails()
			<< ", State: " << activity.GetState()
			<< ", Emoji: " << activity.GetEmoji()
			<< ", Party: " << activity.GetParty()
			<< ", Assets: " << activity.GetAssets()
			<< ", Secrets: " << activity.GetSecrets()
			<< ", Instance: " << activity.IsInstance()
			<< ", Flags: " << activity.GetFlags();
		return os;
	}
}
