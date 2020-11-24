#pragma once

#ifndef _WIN32
#error HyperDiscord is only supporting Windows in the moment
#endif

#include <sstream>

#include "Event.h"
#include "Objects/Guild.h"
#include "Objects/User.h"

namespace HyperDiscord
{
	class ReadyEvent : public Event
	{
	private:
		uint8_t m_Version;
		User m_User;
		std::vector<Guild> m_Guilds;
		std::string m_SessionId;
		// TODO: Shards

	public:
		ReadyEvent(uint8_t version, User user, std::vector<Guild> guilds, const std::string& sessionId)
			: m_Version(version), m_User(user), m_Guilds(guilds), m_SessionId(sessionId) {}

		uint8_t GetVersion() const { return m_Version; }
		User GetUser() const { return m_User; }
		std::vector<Guild> GetGuilds() const { return m_Guilds; }
		std::string GetSessionId() const { return m_SessionId; }

		std::string ToString() const override
		{
			std::stringstream ss;
			// TODO: Guild Array Output
			ss << "ReadyEvent: " << m_Version << ", " << m_User << ", " << m_SessionId;
			return ss.str();
		}

		EVENT_CLASS_TYPE(Ready)
		EVENT_CLASS_CATEGORY(GeneralCategory)
	};
}
