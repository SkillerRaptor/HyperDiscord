#include "ActivityEmoji.h"
#include "ActivityParty.h"

namespace HyperDiscord
{
	ActivityParty::ActivityParty(const std::string& id, std::array<uint16_t, 2> size)
		: m_Id(id), m_Size(size)
	{
	}

	void ActivityParty::SetId(const std::string& id)
	{
		m_Id = id;
	}

	const std::string& ActivityParty::GetId() const
	{
		return m_Id;
	}

	void ActivityParty::SetSize(std::array<uint16_t, 2> size)
	{
		m_Size = size;
	}

	std::array<uint16_t, 2> ActivityParty::GetSize() const
	{
		return m_Size;
	}
}
