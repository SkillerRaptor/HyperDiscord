#pragma once

#include <string>
#include <vector>

#include "Role.h"
#include "Snowflake.h"
#include "User.h"

namespace HyperDiscord
{
	/* https://discord.com/developers/docs/resources/emoji#emoji-object-emoji-structure */
	struct Emoji
	{
		Snowflake Id;
		std::string Name;
		std::vector<Role> Roles;
		User User;
		bool RequireColons;
		bool Managed;
		bool Animated;
		bool Available;

		friend std::ostream& operator<<(std::ostream& os, const Emoji& emoji);
	};

	inline std::ostream& operator<<(std::ostream& os, const Emoji& emoji)
	{
		os << "Id: " << emoji.Id
			<< ", Name: " << emoji.Name
			//<< ", Roles: " << emoji.Roles
			<< ", User: " << emoji.User
			<< ", Require Colons: " << emoji.RequireColons
			<< ", Managed: " << emoji.Managed
			<< ", Animated: " << emoji.Animated
			<< ", Available: " << emoji.Available;
		return os;
	}
}
