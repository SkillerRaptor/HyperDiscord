#pragma once

#include <string>

class Iso8601
{
private:
	uint16_t m_Year;
	uint8_t m_Month;
	uint8_t m_Day;
	uint8_t m_Hour;
	uint8_t m_Minute;
	uint8_t m_Seconds;
	uint16_t m_Milliseconds;

public:
	Iso8601(const std::string& timeStamp);
};
