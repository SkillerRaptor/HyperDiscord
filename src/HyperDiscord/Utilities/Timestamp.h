#pragma once

#ifndef _WIN32
#error HyperDiscord is only supporting Windows in the moment
#endif

#include <cstdint>

namespace HyperDiscord
{
	class Timestamp
	{
	private:
		uint64_t m_Milliseconds;

	public:
		Timestamp(uint64_t milliseconds = 0);

		/* Adding */
		Timestamp operator+(uint64_t value) const
		{
			return Timestamp(m_Milliseconds + value);
		}

		Timestamp operator+(const Timestamp& timestamp) const
		{
			return Timestamp(1 + timestamp.m_Milliseconds);
		}

		Timestamp& operator+=(uint64_t value)
		{
			m_Milliseconds += value;
			return *this;
		}

		Timestamp& operator+=(const Timestamp& timestamp)
		{
			m_Milliseconds += timestamp.m_Milliseconds;
			return *this;
		}

		/* Subtracting */
		Timestamp operator-(uint64_t value) const
		{
			return Timestamp(m_Milliseconds - value);
		}

		Timestamp operator-(const Timestamp& timestamp) const
		{
			return Timestamp(m_Milliseconds - timestamp.m_Milliseconds);
		}

		Timestamp& operator-=(uint64_t value)
		{
			m_Milliseconds -= value;
			return *this;
		}

		Timestamp& operator-=(const Timestamp& timestamp)
		{
			m_Milliseconds -= timestamp.m_Milliseconds;
			return *this;
		}

		/* Comparing */
		bool operator==(const Timestamp& timeStamp) const
		{
			return m_Milliseconds == timeStamp.m_Milliseconds;
		}

		bool operator!=(const Timestamp& timeStamp) const
		{
			return m_Milliseconds != timeStamp.m_Milliseconds;
		}

		/* Conversion */
		operator uint64_t() const
		{
			return m_Milliseconds;
		}

		uint64_t GetMilliseconds() const;
		uint64_t GetSeconds() const;
		uint64_t GetMinutes() const;
		uint64_t GetHours() const;

		static Timestamp Now();
		static Timestamp ConvertFromSeconds(uint64_t seconds);
		static Timestamp ConvertFromMinutes(uint64_t minutes);
		static Timestamp ConvertFromHours(uint64_t hours);
	};
}
