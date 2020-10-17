#include "Activity.h"

namespace HyperDiscord
{
    Activity::Activity(const std::string& name, ActivityType type, const std::string& url, uint64_t createdAt, ActivityTimestamp timestamps, Snowflake applicationId, const std::string& details, const std::string& state, ActivityEmoji emoji, ActivityParty party, ActivityAssets assets, ActivitySecrets secrets, bool instance, uint32_t flags)
		: m_Name(name), m_Type(type), m_Url(url), m_CreatedAt(createdAt), m_Timestamps(timestamps), m_ApplicationId(applicationId), m_Details(details), m_State(state), m_Emoji(emoji), m_Party(party), m_Assets(assets), m_Secrets(secrets), m_Instance(instance), m_Flags(flags)
	{
    }

    void Activity::SetName(const std::string& name)
    {
		m_Name = name;
    }

	const std::string& Activity::GetName() const
	{
		return m_Name;
	}

	void Activity::SetType(ActivityType type)
	{
		m_Type = type;
	}

	ActivityType Activity::GetType() const
	{
		return m_Type;
	}

	void Activity::SetUrl(const std::string& url)
	{
		m_Url = url;
	}

	const std::string& Activity::GetUrl() const
	{
		return m_Url;
	}

	void Activity::SetCreatedAt(uint64_t createdAt)
	{
		m_CreatedAt = createdAt;
	}

	uint64_t Activity::GetCreatedAt() const
	{
		return m_CreatedAt;
	}

	void Activity::SetTimestamps(ActivityTimestamp timestamps)
	{
		m_Timestamps = timestamps;
	}

	ActivityTimestamp Activity::GetTimestamps() const
	{
		return m_Timestamps;
	}

	void Activity::SetApplicationId(Snowflake applicationId)
	{
		m_ApplicationId = applicationId;
	}

	Snowflake Activity::GetApplicationId() const
	{
		return m_ApplicationId;
	}

	void Activity::SetDetails(const std::string& details)
	{
		m_Details = details;
	}

	const std::string& Activity::GetDetails() const
	{
		return m_Details;
	}

	void Activity::SetState(const std::string& state)
	{
		m_State = state;
	}

	const std::string& Activity::GetState() const
	{
		return m_State;
	}

	void Activity::SetEmoji(ActivityEmoji emoji)
	{
		m_Emoji = emoji;
	}

	ActivityEmoji Activity::GetEmoji() const
	{
		return m_Emoji;
	}

	void Activity::SetParty(ActivityParty party)
	{
		m_Party = party;
	}

	ActivityParty Activity::GetParty() const
	{
		return m_Party;
	}

	void Activity::SetAssets(ActivityAssets assets)
	{
		m_Assets = assets;
	}

	ActivityAssets Activity::GetAssets() const
	{
		return m_Assets;
	}

	void Activity::SetSecrets(ActivitySecrets secrets)
	{
		m_Secrets = secrets;
	}

	ActivitySecrets Activity::GetSecrets() const
	{
		return m_Secrets;
	}

	void Activity::SetInstance(bool instance)
	{
		m_Instance = instance;
	}

	bool Activity::IsInstance() const
	{
		return m_Instance;
	}

	void Activity::SetFlags(uint32_t flags)
	{
		m_Flags = flags;
	}

	uint32_t Activity::GetFlags() const
	{
		return m_Flags;
	}
}
