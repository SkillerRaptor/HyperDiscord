#pragma once

#include <iostream>
#include <string>

#include "Snowflake.h"

namespace HyperDiscord
{
	/* https://discord.com/developers/docs/topics/permissions#role-object-role-structure */
	class Role
	{
	private:
		Snowflake m_Id;
		std::string m_Name;
		uint32_t m_Color;
		bool m_Hoist;
		uint16_t m_Position;
		std::string m_Permissions;
		bool m_Managed;
		bool m_Mentionable;

	public:
		Role(Snowflake id, const std::string& name, uint32_t color, bool hoist, uint16_t position, const std::string& permissions, bool managed, bool mentionable);

		void SetId(Snowflake id);
		Snowflake GetId() const;

		void SetName(const std::string& name);
		const std::string& GetName() const;

		void SetColor(uint32_t color);
		uint32_t GetColor() const;

		void SetHoist(bool hoist);
		bool IsHoist() const;

		void SetPosition(uint16_t position);
		uint16_t GetPosition() const;

		void SetPermissions(const std::string& permissions);
		const std::string& GetPermissions() const;

		void SetManaged(bool managed);
		bool IsManaged() const;

		void SetMentionable(bool mentionable);
		bool IsMentionable() const;

		friend std::ostream& operator<<(std::ostream& os, const Role& role);
	};

	inline std::ostream& operator<<(std::ostream& os, const Role& role)
	{
		os << "Id: " << role.GetId()
			<< ", Name: " << role.GetName()
			<< ", Color: " << role.GetColor()
			<< ", Hoist: " << role.IsHoist()
			<< ", Position: " << role.GetPosition()
			<< ", Permissions: " << role.GetPermissions()
			<< ", Managed: " << role.IsManaged()
			<< ", Mentionable: " << role.IsMentionable();
		return os;
	}
}
