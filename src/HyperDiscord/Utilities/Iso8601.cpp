#include "Iso8601.h"

#include <iostream>

namespace HyperDiscord
{
	Iso8601::Iso8601(const std::string& timeStamp)
	{
		sscanf(timeStamp.c_str(), "%d-%d-%dT%d:%d:%d.%d", (uint32_t*)&m_Year, (uint32_t*)&m_Month, (uint32_t*)&m_Day, (uint32_t*)&m_Hour, (uint32_t*)&m_Minute, (uint32_t*)&m_Second, (uint32_t*)&m_Nanosecond);
	}

	uint16_t Iso8601::GetYear() const
	{
		return m_Year;
	}

	uint16_t Iso8601::GetMonth() const
	{
		return m_Month;
	}

	uint16_t Iso8601::GetDay() const
	{
		return m_Day;
	}

	uint16_t Iso8601::GetHour() const
	{
		return m_Hour;
	}

	uint16_t Iso8601::GetMinute() const
	{
		return m_Minute;
	}

	uint16_t Iso8601::GetSecond() const
	{
		return m_Second;
	}

	uint16_t Iso8601::GetNanosecond() const
	{
		return m_Nanosecond;
	}
}
