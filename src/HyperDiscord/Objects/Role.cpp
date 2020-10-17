#include "Role.h"

namespace HyperDiscord
{
	Role::Role(Snowflake id, const std::string& name, uint32_t color, bool hoist, uint16_t position, const std::string& permissions, bool managed, bool mentionable)
		: m_Id(id), m_Name(name), m_Color(color), m_Hoist(hoist), m_Position(position), m_Permissions(permissions), m_Managed(managed), m_Mentionable(mentionable)
	{
	}

	void Role::SetId(Snowflake id)
	{
		m_Id = id;
	}

	Snowflake Role::GetId() const
	{
		return m_Id;
	}

	void Role::SetName(const std::string& name)
	{
		m_Name = name;
	}

	const std::string& Role::GetName() const
	{
		return m_Name;
	}

	void Role::SetColor(uint32_t color)
	{
		m_Color = color;
	}

	uint32_t Role::GetColor() const
	{
		return m_Color;
	}

	void Role::SetHoist(bool hoist)
	{
		m_Hoist = hoist;
	}

	bool Role::IsHoist() const
	{
		return m_Hoist;
	}

	void Role::SetPosition(uint16_t position)
	{
		m_Position = position;
	}

	uint16_t Role::GetPosition() const
	{
		return m_Position;
	}

	void Role::SetPermissions(const std::string& permissions)
	{
		m_Permissions = permissions;
	}

	const std::string& Role::GetPermissions() const
	{
		return m_Permissions;
	}

	void Role::SetManaged(bool managed)
	{
		m_Managed = managed;
	}

	bool Role::IsManaged() const
	{
		return m_Managed;
	}

	void Role::SetMentionable(bool mentionable)
	{
		m_Mentionable = mentionable;
	}

	bool Role::IsMentionable() const
	{
		return m_Mentionable;
	}
}
