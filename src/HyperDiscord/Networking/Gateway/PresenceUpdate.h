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
	struct PresenceUpdate
	{
		User User;
		Snowflake GuildId;
		std::string Status;
		std::vector<Activity> Activities;
		ClientStatus ClientStatus;

		friend std::ostream& operator<<(std::ostream& os, const PresenceUpdate& presenceUpdate);
	};

	inline std::ostream& operator<<(std::ostream& os, const PresenceUpdate& presenceUpdate)
	{
		os << "User: " << presenceUpdate.User
			<< "Guild Id: " << presenceUpdate.GuildId
			<< "Status: " << presenceUpdate.Status
			//<< "Activities: " << presenceUpdate.Activities
			<< "Client Status: " << presenceUpdate.ClientStatus;
		return os;
	}
}
