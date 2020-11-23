#pragma once

#ifndef _WIN32
#error HyperDiscord is only supporting Windows in the moment
#endif

#include <iostream>

namespace HyperDiscord
{
	enum class EventType : uint8_t
	{
		None = 0,
		MessageCreate, MessageUpdate, MessageDelete
	};

	enum EventCategory : uint8_t
	{
		NoneCategory = 0,
		GeneralCategory,
		ChannelCategory,
		GuildCategory,
		InviteCategory,
		MessageCategory
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticEventType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticEventType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class Event
	{
	public:
		virtual ~Event() = default;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}
	};

	class EventDispatcher
	{
	private:
		Event& m_Event;

	public:

		EventDispatcher(Event& event)
			: m_Event(event)
		{}

		template<typename T, typename F>
		bool Dispatch(const F& function)
		{
			if (m_Event.GetEventType() == T::GetStaticEventType())
			{
				function(static_cast<T&>(m_Event));
				return true;
			}
			return false;
		}
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& event)
	{
		return os << event.ToString();
	}
}
