#pragma once

#ifndef _WIN32
#error HyperDiscord is only supporting Windows in the moment
#endif

#include <string>

namespace HyperDiscord
{
	/* https://discord.com/developers/docs/reference#iso8601-datetime */
	class Iso8601
	{
	private:
		uint16_t m_Year;
		uint8_t m_Month;
		uint8_t m_Day;
		uint8_t m_Hour;
		uint8_t m_Minute;
		uint8_t m_Second;
		uint32_t m_Nanosecond;

	public:
		Iso8601(const std::string& timeStamp = "");

		uint16_t GetYear() const;
		uint16_t GetMonth() const;
		uint16_t GetDay() const;
		uint16_t GetHour() const;
		uint16_t GetMinute() const;
		uint16_t GetSecond() const;
		uint16_t GetNanosecond() const;
	};
}
