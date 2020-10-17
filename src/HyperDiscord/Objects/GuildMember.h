#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Role.h"
#include "User.h"
#include "Utilities/Iso8601.h"

namespace HyperDiscord
{
	/* https://discord.com/developers/docs/resources/guild#guild-member-object-guild-member-structure */
	class GuildMember
	{
	private:
		User m_User;
		std::string m_Nick;
		std::vector<Role> m_Roles;
		Iso8601 m_JoinedAt;
		Iso8601 m_PremiumSince;
		bool m_Deaf;
		bool m_Mute;

	public:
		GuildMember(User user, const std::string& nick, std::vector<Role> roles, Iso8601 joinedAt, Iso8601 premiumSince, bool deaf, bool mute);

		void SetUser(User user);
		User GetUser() const;

		void SetNick(const std::string& nick);
		const std::string& GetNick() const;

		void SetRoles(std::vector<Role> roles);
		std::vector<Role> GetRoles() const;

		void SetJoinedAt(Iso8601 joinedAt);
		Iso8601 GetJoinedAt() const;

		void SetPremiumSince(Iso8601 premiumSince);
		Iso8601 GetPremiumSince() const;

		void SetDeaf(bool deaf);
		bool IsDeaf() const;

		void SetMute(bool mute);
		bool IsMute() const;

		friend std::ostream& operator<<(std::ostream& os, const GuildMember& guildMember);
	};

	inline std::ostream& operator<<(std::ostream& os, const GuildMember& guildMember)
	{
		os << "User: " << guildMember.GetUser()
			<< ", Nick " << guildMember.GetNick()
			//<< ", Roles: " << guildMember.GetRoles()
			//<< ", Joined At: " << guildMember.GetJoinedAt()
			//<< ", Premium Since: " << guildMember.GetPremiumSince()
			<< ", Deaf: " << guildMember.IsDeaf()
			<< ", Mute: " << guildMember.IsMute();
		return os;
	}
}
