#pragma once

#ifndef _WIN32
#error HyperDiscord is only supporting Windows in the moment
#endif

#include <iostream>

namespace HyperDiscord
{
	/* https://discord.com/developers/docs/topics/gateway#activity-object-activity-timestamps */
	struct ActivityTimestamp
	{
		uint64_t Start;
		uint64_t End;

		friend std::ostream& operator<<(std::ostream& os, const ActivityTimestamp& activityTimestamp);
	};

	inline std::ostream& operator<<(std::ostream& os, const ActivityTimestamp& activityTimestamp)
	{
		os << "Start: " << activityTimestamp.Start
			<< ", End: " << activityTimestamp.End;
		return os;
	}
}
