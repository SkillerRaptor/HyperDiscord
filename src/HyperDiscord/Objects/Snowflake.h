#pragma once

#ifndef _WIN32
#error HyperDiscord is only supporting Windows in the moment
#endif

#include <cstdint>

#include "Utilities/Timestamp.h"

namespace HyperDiscord
{
	/* https://discord.com/developers/docs/reference#snowflakes-snowflake-id-format-structure-left-to-right */
	class Snowflake
	{
	private:
		long long m_Id;

	public:
		Snowflake(long long id = -1);
		Snowflake(Timestamp timeStamp);

		long long GetId() const;
		Timestamp GetTimestamp() const;
		uint64_t GetInternalWorkerId() const;
		uint64_t GetInternalProcessId() const;
		uint64_t GetIncrement() const;

		operator long long() const;
	};
}
