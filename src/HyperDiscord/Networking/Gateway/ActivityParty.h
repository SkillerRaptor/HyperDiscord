#pragma once

#include <array>
#include <iostream>
#include <string>

namespace HyperDiscord
{
	/* https://discord.com/developers/docs/topics/gateway#activity-object-activity-party */
	class ActivityParty
	{
	private:
		std::string m_Id;
		std::array<uint16_t, 2> m_Size;

	public:
		ActivityParty(const std::string& id, std::array<uint16_t, 2> size);

		void SetId(const std::string& id);
		const std::string& GetId() const;

		void SetSize(std::array<uint16_t, 2> size);
		std::array<uint16_t, 2> GetSize() const;

		friend std::ostream& operator<<(std::ostream& os, const ActivityParty& activityParty);
	};

	inline std::ostream& operator<<(std::ostream& os, const ActivityParty& activityParty)
	{
		os << "Id: " << activityParty.GetId();
			//<< ", Size: " << activityParty.GetSize();
		return os;
	}
}
