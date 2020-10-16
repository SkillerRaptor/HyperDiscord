#pragma once

#include <cstdint>

class Timestamp
{
private:
	uint64_t m_Milliseconds;

public:
	Timestamp(uint64_t milliseconds);

	uint64_t GetMilliseconds() const;
	uint64_t GetSeconds() const;
	uint64_t GetMinutes() const;
	uint64_t GetHours() const;

	static Timestamp ConvertFromSeconds(uint64_t seconds);
	static Timestamp ConvertFromMinutes(uint64_t minutes);
	static Timestamp ConvertFromHours(uint64_t hours);
};