#pragma once

#ifndef _WIN32
#error HyperDiscord is only supporting Windows in the moment
#endif

#include <array>
#include <iostream>
#include <string>

namespace HyperDiscord
{
	/* https://discord.com/developers/docs/topics/gateway#activity-object-activity-party */
	struct ActivityParty
	{
	private:
		std::string Id;
		std::array<uint16_t, 2> Size;

		friend std::ostream& operator<<(std::ostream& os, const ActivityParty& activityParty);
	};

	inline std::ostream& operator<<(std::ostream& os, const ActivityParty& activityParty)
	{
		os << "Id: " << activityParty.Id;
			//<< ", Size: " << activityParty.Size;
		return os;
	}
}
