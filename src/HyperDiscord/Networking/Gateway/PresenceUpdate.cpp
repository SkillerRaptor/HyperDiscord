#include "PresenceUpdate.h"

namespace HyperDiscord
{
	PresenceUpdate::PresenceUpdate(User user, Snowflake guildId, const std::string& status, std::vector<Activity> activities, ClientStatus clientStatus)
		: m_User(user), m_GuildId(guildId), m_Status(status), m_Activities(activities), m_ClientStatus(clientStatus)
	{
	}

	void PresenceUpdate::SetUser(User user)
	{
		m_User = user;
	}

	User PresenceUpdate::GetUser() const
	{
		return m_User;
	}

	void PresenceUpdate::SetGuildId(Snowflake guildId)
	{
		m_GuildId = guildId;
	}

	Snowflake PresenceUpdate::GetGuildId() const
	{
		return m_GuildId;
	}

	void PresenceUpdate::SetStatus(const std::string& status)
	{
		m_Status = status;
	}

	const std::string& PresenceUpdate::GetStatus() const
	{
		return m_Status;
	}

	void PresenceUpdate::SetActivities(std::vector<Activity> activities)
	{
		m_Activities = activities;
	}

	std::vector<Activity> PresenceUpdate::GetActivities() const
	{
		return m_Activities;
	}

	void PresenceUpdate::SetClientStatus(ClientStatus clientStatus)
	{
		m_ClientStatus = clientStatus;
	}

	ClientStatus PresenceUpdate::GetClientStatus() const
	{
		return m_ClientStatus;
	}
}
