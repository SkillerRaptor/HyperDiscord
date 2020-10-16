#include "Timestamp.h"

namespace HyperDiscord
{
	Timestamp::Timestamp(uint64_t milliseconds)
		: m_Milliseconds(milliseconds)
	{
	}

	uint64_t Timestamp::GetMilliseconds() const
	{
		return m_Milliseconds;
	}

	uint64_t Timestamp::GetSeconds() const
	{
		return m_Milliseconds / 1000;
	}

	uint64_t Timestamp::GetMinutes() const
	{
		return m_Milliseconds / 60000;
	}

	uint64_t Timestamp::GetHours() const
	{
		return m_Milliseconds / 3600000;
	}

	Timestamp Timestamp::ConvertFromSeconds(uint64_t seconds)
	{
		return Timestamp(seconds * 1000);
	}

	Timestamp Timestamp::ConvertFromMinutes(uint64_t minutes)
	{
		return Timestamp(minutes * 60000);
	}

	Timestamp Timestamp::ConvertFromHours(uint64_t hours)
	{
		return Timestamp(hours * 3600000);
	}
}
