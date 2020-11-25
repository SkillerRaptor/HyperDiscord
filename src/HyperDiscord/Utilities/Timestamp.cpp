#include "Timestamp.h"

#include <chrono>

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

	float Timestamp::GetSeconds() const
	{
		return (float) m_Milliseconds / 1000;
	}

	float Timestamp::GetMinutes() const
	{
		return (float) m_Milliseconds / 60000;
	}

	float Timestamp::GetHours() const
	{
		return (float) m_Milliseconds / 3600000;
	}

	Timestamp Timestamp::Now()
	{
		return Timestamp(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
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
