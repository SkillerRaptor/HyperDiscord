#pragma once

#include <iostream>

namespace HyperDiscord
{
	/* https://discord.com/developers/docs/topics/gateway#activity-object-activity-timestamps */
	class ActivityTimestamp
	{
	private:
		uint64_t m_Start;
		uint64_t m_End;

	public:
		ActivityTimestamp(uint64_t start, uint64_t end);

		void SetStart(uint64_t start);
		uint64_t GetStart() const;

		void SetEnd(uint64_t end);
		uint64_t GetEnd() const;

		friend std::ostream& operator<<(std::ostream& os, const ActivityTimestamp& activityTimestamp);
	};

	inline std::ostream& operator<<(std::ostream& os, const ActivityTimestamp& activityTimestamp)
	{
		os << "Start: " << activityTimestamp.GetStart()
			<< ", End: " << activityTimestamp.GetEnd();
		return os;
	}
}
