#pragma once

#ifndef _WIN32
#error HyperDiscord is only supporting Windows in the moment
#endif

#include <iostream>
#include <string>
#include <vector>

#include "Role.h"
#include "User.h"
#include "Utilities/Iso8601.h"

namespace HyperDiscord
{
	/* https://discord.com/developers/docs/resources/guild#guild-member-object-guild-member-structure */
	struct GuildMember
	{
		User User;
		std::string Nick;
		std::vector<Role> Roles;
		Iso8601 JoinedAt;
		Iso8601 PremiumSince;
		bool Deaf;
		bool Mute;

		friend std::ostream& operator<<(std::ostream& os, const GuildMember& guildMember);
	};

	inline std::ostream& operator<<(std::ostream& os, const GuildMember& guildMember)
	{
		os << "User: " << guildMember.User
			<< ", Nick " << guildMember.Nick
			//<< ", Roles: " << guildMember.Roles
			//<< ", Joined At: " << guildMember.JoinedAt
			//<< ", Premium Since: " << guildMember.PremiumSince
			<< ", Deaf: " << guildMember.Deaf
			<< ", Mute: " << guildMember.Mute;
		return os;
	}
}
