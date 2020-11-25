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

	class InviteCreateEvent : public Event
	{
	private:

	public:
		InviteCreateEvent() {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "InviteCreateEvent: ";
			return ss.str();
		}

		EVENT_CLASS_TYPE(InviteCreate)
		EVENT_CLASS_CATEGORY(GeneralCategory)
	};

	class InviteDeleteEvent : public Event
	{
	private:

	public:
		InviteDeleteEvent() {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "InviteDeleteEvent: ";
			return ss.str();
		}

		EVENT_CLASS_TYPE(InviteDelete)
		EVENT_CLASS_CATEGORY(GeneralCategory)
	};

	class PresenceUpdateEvent : public Event
	{
	private:

	public:
		PresenceUpdateEvent() {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "PresenceUpdateEvent: ";
			return ss.str();
		}

		EVENT_CLASS_TYPE(PresenceUpdate)
		EVENT_CLASS_CATEGORY(GeneralCategory)
	};

	class TypingStartEvent : public Event
	{
	private:

	public:
		TypingStartEvent() {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "TypingStartEvent: ";
			return ss.str();
		}

		EVENT_CLASS_TYPE(TypingStart)
		EVENT_CLASS_CATEGORY(GeneralCategory)
	};

	class UserUpdateEvent : public Event
	{
	private:

	public:
		UserUpdateEvent() {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "UserUpdateEvent: ";
			return ss.str();
		}

		EVENT_CLASS_TYPE(UserUpdate)
		EVENT_CLASS_CATEGORY(GeneralCategory)
	};

	class VoiceStateUpdateEvent : public Event
	{
	private:

	public:
		VoiceStateUpdateEvent() {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "VoiceStateUpdateEvent: ";
			return ss.str();
		}

		EVENT_CLASS_TYPE(VoiceStateUpdate)
		EVENT_CLASS_CATEGORY(GeneralCategory)
	};

	class VoiceServerUpdateEvent : public Event
	{
	private:

	public:
		VoiceServerUpdateEvent() {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "VoiceServerUpdateEvent: ";
			return ss.str();
		}

		EVENT_CLASS_TYPE(VoiceServerUpdate)
		EVENT_CLASS_CATEGORY(GeneralCategory)
	};

	class WebhooksUpdateEvent : public Event
	{
	private:

	public:
		WebhooksUpdateEvent() {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WebhooksUpdateEvent: ";
			return ss.str();
		}

		EVENT_CLASS_TYPE(WebhooksUpdate)
		EVENT_CLASS_CATEGORY(GeneralCategory)
	};
}
