#include "Overwrite.h"

namespace HyperDiscord
{
	Overwrite::Overwrite(Snowflake id, OverwriteType type, const std::string& allow, const std::string& deny)
		: m_Id(id), m_Type(type), m_Allow(allow), m_Deny(deny)
	{
	}

	void Overwrite::SetId(Snowflake id)
	{
		m_Id = id;
	}

	Snowflake Overwrite::GetId() const
	{
		return m_Id;;
	}

	void Overwrite::SetType(OverwriteType type)
	{
		m_Type = type;
	}

	OverwriteType Overwrite::GetType() const
	{
		return m_Type;
	}

	void Overwrite::SetAllow(const std::string& allow)
	{
		m_Allow = allow;
	}

	std::string Overwrite::GetAllow() const
	{
		return m_Allow;
	}

	void Overwrite::SetDeny(const std::string& deny)
	{
		m_Deny = deny;
	}

	std::string Overwrite::GetDeny() const
	{
		return m_Deny;
	}
}
