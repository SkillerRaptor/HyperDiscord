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

	class GuildUpdateEvent : public Event
	{
	private:

	public:
		GuildUpdateEvent() {};

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "GuildUpdateEvent: ";
			return ss.str();
		}

		EVENT_CLASS_TYPE(GuildUpdate)
		EVENT_CLASS_CATEGORY(GuildCategory)
	};

	class GuildDeleteEvent : public Event
	{
	private:

	public:
		GuildDeleteEvent() {};

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "GuildDeleteEvent: ";
			return ss.str();
		}

		EVENT_CLASS_TYPE(GuildDelete)
		EVENT_CLASS_CATEGORY(GuildCategory)
	};

	class GuildBanAddEvent : public Event
	{
	private:

	public:
		GuildBanAddEvent() {};

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "GuildBanAddEvent: ";
			return ss.str();
		}

		EVENT_CLASS_TYPE(GuildBanAdd)
		EVENT_CLASS_CATEGORY(GuildCategory)
	};

	class GuildBanRemoveEvent : public Event
	{
	private:

	public:
		GuildBanRemoveEvent() {};

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "GuildBanRemoveEvent: ";
			return ss.str();
		}

		EVENT_CLASS_TYPE(GuildBanRemove)
		EVENT_CLASS_CATEGORY(GuildCategory)
	};

	class GuildEmojisUpdateEvent : public Event
	{
	private:

	public:
		GuildEmojisUpdateEvent() {};

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "GuildEmojisUpdateEvent: ";
			return ss.str();
		}

		EVENT_CLASS_TYPE(GuildEmojisUpdate)
		EVENT_CLASS_CATEGORY(GuildCategory)
	};

	class GuildIntegrationsUpdateEvent : public Event
	{
	private:

	public:
		GuildIntegrationsUpdateEvent() {};

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "GuildIntegrationsUpdateEvent: ";
			return ss.str();
		}

		EVENT_CLASS_TYPE(GuildIntegrationsUpdate)
		EVENT_CLASS_CATEGORY(GuildCategory)
	};

	class GuildMemberAddEvent : public Event
	{
	private:

	public:
		GuildMemberAddEvent() {};

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "GuildMemberAddEvent: ";
			return ss.str();
		}

		EVENT_CLASS_TYPE(GuildMemberAdd)
		EVENT_CLASS_CATEGORY(GuildCategory)
	};

	class GuildMemberUpdateEvent : public Event
	{
	private:

	public:
		GuildMemberUpdateEvent() {};

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "GuildMemberUpdateEvent: ";
			return ss.str();
		}

		EVENT_CLASS_TYPE(GuildMemberUpdate)
		EVENT_CLASS_CATEGORY(GuildCategory)
	};

	class GuildMemberRemoveEvent : public Event
	{
	private:

	public:
		GuildMemberRemoveEvent() {};

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "GuildMemberRemoveEvent: ";
			return ss.str();
		}

		EVENT_CLASS_TYPE(GuildMemberRemove)
		EVENT_CLASS_CATEGORY(GuildCategory)
	};

	class GuildMemberChunkEvent : public Event
	{
	private:

	public:
		GuildMemberChunkEvent() {};

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "GuildMemberChunkEvent: ";
			return ss.str();
		}

		EVENT_CLASS_TYPE(GuildMemberChunk)
		EVENT_CLASS_CATEGORY(GuildCategory)
	};

	class GuildRoleCreateEvent : public Event
	{
	private:

	public:
		GuildRoleCreateEvent() {};

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "GuildRoleCreateEvent: ";
			return ss.str();
		}

		EVENT_CLASS_TYPE(GuildRoleCreate)
		EVENT_CLASS_CATEGORY(GuildCategory)
	};

	class GuildRoleUpdateEvent : public Event
	{
	private:

	public:
		GuildRoleUpdateEvent() {};

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "GuildRoleUpdateEvent: ";
			return ss.str();
		}

		EVENT_CLASS_TYPE(GuildRoleUpdate)
		EVENT_CLASS_CATEGORY(GuildCategory)
	};

	class GuildRoleDeleteEvent : public Event
	{
	private:

	public:
		GuildRoleDeleteEvent() {};

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "GuildRoleDeleteEvent: ";
			return ss.str();
		}

		EVENT_CLASS_TYPE(GuildRoleDelete)
		EVENT_CLASS_CATEGORY(GuildCategory)
	};
}
