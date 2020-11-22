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
	class ActivityEmoji
	{
	private:
		std::string m_Name;
		Snowflake m_Id;
		bool m_Animated;

	public:
		ActivityEmoji(const std::string& name, Snowflake id, bool animated);

		void SetName(const std::string& name);
		const std::string& GetName() const;

		void SetId(Snowflake id);
		Snowflake GetId() const;

		void SetAnimated(bool animated);
		bool IsAnimated() const;

		friend std::ostream& operator<<(std::ostream& os, const ActivityEmoji& activityEmoji);
	};

	inline std::ostream& operator<<(std::ostream& os, const ActivityEmoji& activityEmoji)
	{
		os << "Name: " << activityEmoji.GetName()
			<< ", Id: " << activityEmoji.GetId()
			<< ", Animated: " << activityEmoji.IsAnimated();
		return os;
	}
}
