#pragma once

#ifndef _WIN32
#error HyperDiscord is only supporting Windows in the moment
#endif

#include <iostream>
#include <string>

#include "Objects/Snowflake.h"

namespace HyperDiscord
{
	/* https://discord.com/developers/docs/topics/gateway#activity-object-activity-emoji */
	struct ActivityEmoji
	{
		std::string Name;
		Snowflake Id;
		bool Animated;

		friend std::ostream& operator<<(std::ostream& os, const ActivityEmoji& activityEmoji);
	};

	inline std::ostream& operator<<(std::ostream& os, const ActivityEmoji& activityEmoji)
	{
		os << "Name: " << activityEmoji.Name
			<< ", Id: " << activityEmoji.Id
			<< ", Animated: " << activityEmoji.Animated;
		return os;
	}
}
