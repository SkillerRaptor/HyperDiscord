#include "GuildMember.h"

namespace HyperDiscord
{
	GuildMember::GuildMember(User user, const std::string& nick, std::vector<Role> roles, Iso8601 joinedAt, Iso8601 premiumSince, bool deaf, bool mute)
		: m_User(user), m_Nick(nick), m_Roles(roles), m_JoinedAt(joinedAt), m_PremiumSince(premiumSince), m_Deaf(deaf), m_Mute(mute)
	{
	}

	void GuildMember::SetUser(User user)
	{
		m_User = user;
	}

	User GuildMember::GetUser() const
	{
		return m_User;
	}

	void GuildMember::SetNick(const std::string& nick)
	{
		m_Nick = nick;
	}

	const std::string& GuildMember::GetNick() const
	{
		return m_Nick;
	}

	void GuildMember::SetRoles(std::vector<Role> roles)
	{
		m_Roles = roles;
	}

	std::vector<Role> GuildMember::GetRoles() const
	{
		return m_Roles;
	}

	void GuildMember::SetJoinedAt(Iso8601 joinedAt)
	{
		m_JoinedAt = joinedAt;
	}

	Iso8601 GuildMember::GetJoinedAt() const
	{
		return m_JoinedAt;
	}

	void GuildMember::SetPremiumSince(Iso8601 premiumSince)
	{
		m_PremiumSince = premiumSince;
	}

	Iso8601 GuildMember::GetPremiumSince() const
	{
		return m_PremiumSince;
	}

	void GuildMember::SetDeaf(bool deaf)
	{
		m_Deaf = deaf;
	}

	bool GuildMember::IsDeaf() const
	{
		return m_Deaf;
	}

	void GuildMember::SetMute(bool mute)
	{
		m_Mute = mute;
	}

	bool GuildMember::IsMute() const
	{
		return m_Mute;
	}
}
