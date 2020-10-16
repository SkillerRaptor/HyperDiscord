#pragma once

#include <cstdint>

#include "Utilities/Timestamp.h"

class Snowflake
{
private:
	long long m_Id;

public:
	Snowflake(long long id);
	Snowflake(Timestamp timeStamp);

	Timestamp GetTimestamp() const;
	uint64_t GetInternalWorkerId() const;
	uint64_t GetInternalProcessId() const;
	uint64_t GetIncrement() const;
};