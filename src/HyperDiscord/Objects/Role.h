#pragma once

#include <iostream>
#include <string>

#include "Snowflake.h"

namespace HyperDiscord
{
	/* https://discord.com/developers/docs/topics/permissions#role-object-role-structure */
	struct Role
	{
		Snowflake Id;
		std::string Name;
		uint32_t Color;
		bool Hoist;
		uint16_t Position;
		std::string Permissions;
		bool Managed;
		bool Mentionable;

		friend std::ostream& operator<<(std::ostream& os, const Role& role);
	};

	inline std::ostream& operator<<(std::ostream& os, const Role& role)
	{
		os << "Id: " << role.Id
			<< ", Name: " << role.Name
			<< ", Color: " << role.Color
			<< ", Hoist: " << role.Hoist
			<< ", Position: " << role.Position
			<< ", Permissions: " << role.Permissions
			<< ", Managed: " << role.Managed
			<< ", Mentionable: " << role.Mentionable;
		return os;
	}
}
