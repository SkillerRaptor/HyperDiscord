#include "ActivityTimestamp.h"

namespace HyperDiscord
{
	ActivityTimestamp::ActivityTimestamp(uint64_t start, uint64_t end)
		: m_Start(start), m_End(end)
	{
	}

	void ActivityTimestamp::SetStart(uint64_t start)
	{
		m_Start = start;
	}

	uint64_t ActivityTimestamp::GetStart() const
	{
		return m_Start;
	}

	void ActivityTimestamp::SetEnd(uint64_t end)
	{
		m_End = end;
	}

	uint64_t ActivityTimestamp::GetEnd() const
	{
		return m_End;
	}
}
