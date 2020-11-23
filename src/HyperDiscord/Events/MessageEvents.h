#pragma once

#include <sstream>

#include "Event.h"
#include "Objects/Message.h"
#include "Objects/Snowflake.h"

namespace HyperDiscord
{
	class MessageCreateEvent : public Event
	{
	private:
		Message m_Message;

	public:
		MessageCreateEvent(Message message) 
			: m_Message(message) {};

		Message GetMessage() const { return m_Message; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MessageCreateEvent: " << m_Message;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MessageCreate)
		EVENT_CLASS_CATEGORY(MessageCategory)
	};

	class MessageUpdateEvent : public Event
	{
	private:
		Message m_Message;

	public:
		MessageUpdateEvent(Message message)
			: m_Message(message) {};

		Message GetMessage() const { return m_Message; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MessageUpdateEvent: " << m_Message;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MessageUpdate)
		EVENT_CLASS_CATEGORY(MessageCategory)
	};

	class MessageDeleteEvent : public Event
	{
	private:
		Snowflake m_ChannelId;
		Snowflake m_GuildId;
		Snowflake m_Id;

	public:
		MessageDeleteEvent(Snowflake channelId, Snowflake guildId, Snowflake id)
			: m_ChannelId(channelId), m_GuildId(guildId), m_Id(id) {};

		Snowflake GetChannelId() const { return m_ChannelId; }
		Snowflake GetGuildId() const { return m_GuildId; }
		Snowflake GetId() const { return m_Id; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MessageDeleteEvent: " << m_ChannelId << ", " << m_GuildId << ", " << m_Id;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MessageDelete)
		EVENT_CLASS_CATEGORY(MessageCategory)
	};
}
