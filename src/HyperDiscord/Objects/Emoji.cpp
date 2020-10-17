#include "Emoji.h"

namespace HyperDiscord
{
	Emoji::Emoji(Snowflake id, const std::string name, std::vector<Role> roles, User user, bool requireColons, bool managed, bool animated, bool available)
		: m_Id(id), m_Name(name), m_Roles(roles), m_User(user), m_RequireColons(requireColons), m_Managed(managed), m_Animated(animated), m_Available(available)
	{
	}

	void Emoji::SetId(Snowflake id)
	{
		m_Id = id;
	}

	Snowflake Emoji::GetId() const
	{
		return m_Id;
	}

	void Emoji::SetName(const std::string& name)
	{
		m_Name = name;
	}

	const std::string& Emoji::GetName() const
	{
		return m_Name;
	}

	void Emoji::SetRoles(std::vector<Role> roles)
	{
		m_Roles = roles;
	}

	std::vector<Role> Emoji::GetRoles() const
	{
		return m_Roles;
	}

	void Emoji::SetUser(User user)
	{
		m_User = user;
	}

	User Emoji::GetUser() const
	{
		return m_User;
	}

	void Emoji::SetRequireColons(bool requireColons)
	{
		m_RequireColons = requireColons;
	}

	bool Emoji::IsRequireColons() const
	{
		return m_RequireColons;
	}

	void Emoji::SetManaged(bool managed)
	{
		m_Managed = managed;
	}

	bool Emoji::IsManaged() const
	{
		return m_Managed;
	}

	void Emoji::SetAnimated(bool animated)
	{
		m_Animated = animated;
	}

	bool Emoji::IsAnimated() const
	{
		return m_Animated;
	}

	void Emoji::SetAvailable(bool available)
	{
		m_Available = available;
	}

	bool Emoji::IsAvailable() const
	{
		return m_Available;
	}
}
