#pragma once

#ifndef _WIN32
#error HyperDiscord is only supporting Windows in the moment
#endif

#include <iostream>
#include <string>
#include <vector>

#include "Activity.h"
#include "ClientStatus.h"
#include "Objects/Snowflake.h"
#include "Objects/User.h"

namespace HyperDiscord
{
	/* https://discord.com/developers/docs/topics/gateway#presence-update-presence-update-event-fields */
	class PresenceUpdate
	{
	private:
		User m_User;
		Snowflake m_GuildId;
		std::string m_Status;
		std::vector<Activity> m_Activities;
		ClientStatus m_ClientStatus;

	public:
		PresenceUpdate(User user, Snowflake guildId, const std::string& status, std::vector<Activity> activities, ClientStatus clientStatus);

		void SetUser(User user);
		User GetUser() const;

		void SetGuildId(Snowflake guildId);
		Snowflake GetGuildId() const;

		void SetStatus(const std::string& status);
		const std::string& GetStatus() const;

		void SetActivities(std::vector<Activity> activities);
		std::vector<Activity> GetActivities() const;

		void SetClientStatus(ClientStatus clientStatus);
		ClientStatus GetClientStatus() const;

		friend std::ostream& operator<<(std::ostream& os, const PresenceUpdate& presenceUpdate);
	};

	inline std::ostream& operator<<(std::ostream& os, const PresenceUpdate& presenceUpdate)
	{
		os << "User: " << presenceUpdate.GetUser()
			<< "Guild Id: " << presenceUpdate.GetGuildId()
			<< "Status: " << presenceUpdate.GetStatus()
			//<< "Activities: " << presenceUpdate.GetActivities()
			<< "Client Status: " << presenceUpdate.GetClientStatus();
		return os;
	}
}
