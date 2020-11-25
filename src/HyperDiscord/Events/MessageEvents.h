#pragma once

#ifndef _WIN32
#error HyperDiscord is only supporting Windows in the moment
#endif

#include <sstream>

#include "Event.h"
#include "Objects/Message.h"
#include "Objects/Snowflake.h"

#undef GetMessage

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

	class MessageDeleteBulkEvent : public Event
	{
	private:

	public:
		MessageDeleteBulkEvent() {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MessageDeleteBulkEvent: ";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MessageDeleteBulk)
		EVENT_CLASS_CATEGORY(MessageCategory)
	};

	class MessageReactionAddEvent : public Event
	{
	private:

	public:
		MessageReactionAddEvent() {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MessageReactionAddEvent: ";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MessageReactionAdd)
		EVENT_CLASS_CATEGORY(MessageCategory)
	};

	class MessageReactionRemoveEvent : public Event
	{
	private:

	public:
		MessageReactionRemoveEvent() {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MessageReactionRemoveEvent: ";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MessageReactionRemove)
		EVENT_CLASS_CATEGORY(MessageCategory)
	};

	class MessageReactionRemoveAllEvent : public Event
	{
	private:

	public:
		MessageReactionRemoveAllEvent() {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MessageReactionRemoveAllEvent: ";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MessageReactionRemoveAll)
		EVENT_CLASS_CATEGORY(MessageCategory)
	};

	class MessageReactionRemoveEmojiEvent : public Event
	{
	private:

	public:
		MessageReactionRemoveEmojiEvent() {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MessageReactionRemoveEmojiEvent: ";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MessageReactionRemoveEmoji)
		EVENT_CLASS_CATEGORY(MessageCategory)
	};
}
