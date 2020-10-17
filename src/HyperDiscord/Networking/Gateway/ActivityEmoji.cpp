#include "ActivityEmoji.h"

namespace HyperDiscord
{
	ActivityEmoji::ActivityEmoji(const std::string& name, Snowflake id, bool animated)
		: m_Name(name), m_Id(id), m_Animated(animated)
	{
	}

	void ActivityEmoji::SetName(const std::string& name)
	{
		m_Name = name;
	}

	const std::string& ActivityEmoji::GetName() const
	{
		return m_Name;
	}

	void ActivityEmoji::SetId(Snowflake id)
	{
		m_Id = id;
	}

	Snowflake ActivityEmoji::GetId() const
	{
		return m_Id;
	}

	void ActivityEmoji::SetAnimated(bool animated)
	{
		m_Animated = animated;
	}

	bool ActivityEmoji::IsAnimated() const
	{
		return m_Animated;
	}
}
