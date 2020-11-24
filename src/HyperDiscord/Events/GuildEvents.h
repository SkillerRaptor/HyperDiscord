#pragma once

#ifndef _WIN32
#error HyperDiscord is only supporting Windows in the moment
#endif

#include <sstream>

#include "Event.h"
#include "Objects/Guild.h"

namespace HyperDiscord
{
	class GuildCreateEvent : public Event
	{
	private:
		Guild m_Guild;

	public:
		GuildCreateEvent(Guild guild)
			: m_Guild(guild) {};

		Guild GetGuild() const { return m_Guild; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "GuildCreateEvent: " << m_Guild;
			return ss.str();
		}

		EVENT_CLASS_TYPE(GuildCreate)
		EVENT_CLASS_CATEGORY(GuildCategory)
	};
}
