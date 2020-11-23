#pragma once

#ifndef _WIN32
#error HyperDiscord is only supporting Windows in the moment
#endif

#include <iostream>
#include <string>

namespace HyperDiscord
{
	/* https://discord.com/developers/docs/topics/gateway#activity-object-activity-secrets */
	struct ActivitySecrets
	{
		std::string Join;
		std::string Spectate;
		std::string Match;

		friend std::ostream& operator<<(std::ostream& os, const ActivitySecrets& activitySecrets);
	};

	inline std::ostream& operator<<(std::ostream& os, const ActivitySecrets& activitySecrets)
	{
		os << "Join: " << activitySecrets.Join
			<< ", Spectate: " << activitySecrets.Spectate
			<< ", Match: " << activitySecrets.Match;
		return os;
	}
}
