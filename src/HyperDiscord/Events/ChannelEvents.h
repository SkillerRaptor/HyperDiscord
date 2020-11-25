#pragma once

#ifndef _WIN32
#error HyperDiscord is only supporting Windows in the moment
#endif

#include <sstream>

#include "Event.h"

namespace HyperDiscord
{
	class ChannelCreateEvent : public Event
	{
	private:

	public:
		ChannelCreateEvent() {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "ChannelCreateEvent: ";
			return ss.str();
		}

		EVENT_CLASS_TYPE(ChannelCreate)
		EVENT_CLASS_CATEGORY(ChannelCategory)
	};

	class ChannelUpdateEvent : public Event
	{
	private:

	public:
		ChannelUpdateEvent() {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "ChannelUpdateEvent: ";
			return ss.str();
		}

		EVENT_CLASS_TYPE(ChannelUpdate)
		EVENT_CLASS_CATEGORY(ChannelCategory)
	};

	class ChannelDeleteEvent : public Event
	{
	private:

	public:
		ChannelDeleteEvent() {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "ChannelDeleteEvent: ";
			return ss.str();
		}

		EVENT_CLASS_TYPE(ChannelDelete)
		EVENT_CLASS_CATEGORY(ChannelCategory)
	};

	class ChannelPinsUpdateEvent : public Event
	{
	private:

	public:
		ChannelPinsUpdateEvent() {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "ChannelPinsUpdateEvent: ";
			return ss.str();
		}

		EVENT_CLASS_TYPE(ChannelPinsUpdate)
		EVENT_CLASS_CATEGORY(ChannelCategory)
	};
}
