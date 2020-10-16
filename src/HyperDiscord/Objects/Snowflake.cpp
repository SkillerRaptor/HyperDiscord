#include "Snowflake.h"

#include "Utilities/Discord.h"

Snowflake::Snowflake(long long id)
	: m_Id(id)
{
}

Snowflake::Snowflake(Timestamp timeStamp)
	: m_Id((timeStamp.GetMilliseconds() - DISCORD_EPOCH) << 22)
{
}

Timestamp Snowflake::GetTimestamp() const
{
	return Timestamp((m_Id >> 22) + DISCORD_EPOCH);
}

uint64_t Snowflake::GetInternalWorkerId() const
{
	return (m_Id & 0x3F0000) >> 17;
}

uint64_t Snowflake::GetInternalProcessId() const
{
	return (m_Id & 0x1F000) >> 12;
}

uint64_t Snowflake::GetIncrement() const
{
	return m_Id & 0xFFF;
}