#pragma once

#include <string>
#include <vector>

#include "Role.h"
#include "Snowflake.h"
#include "User.h"

namespace HyperDiscord
{
	class Emoji
	{
	private:
		Snowflake m_Id;
		std::string m_Name;
		std::vector<Role> m_Roles;
		User m_User;
		bool m_RequireColons;
		bool m_Managed;
		bool m_Animated;
		bool m_Available;

	public:
		Emoji(Snowflake id, const std::string name, std::vector<Role> roles, User user, bool requireColons, bool managed, bool animated, bool available);

		void SetId(Snowflake id);
		Snowflake GetId() const;

		void SetName(const std::string& name);
		const std::string& GetName() const;

		void SetRoles(std::vector<Role> roles);
		std::vector<Role> GetRoles() const;

		void SetUser(User user);
		User GetUser() const;

		void SetRequireColons(bool requireColons);
		bool IsRequireColons() const;

		void SetManaged(bool managed);
		bool IsManaged() const;

		void SetAnimated(bool animated);
		bool IsAnimated() const;

		void SetAvailable(bool available);
		bool IsAvailable() const;

		friend std::ostream& operator<<(std::ostream& os, const Emoji& emoji);
	};

	inline std::ostream& operator<<(std::ostream& os, const Emoji& emoji)
	{
		os << "Id: " << emoji.GetId()
			<< ", Name: " << emoji.GetName()
			//<< ", Roles: " << emoji.GetRoles()
			<< ", User: " << emoji.GetUser()
			<< ", Require Colons: " << emoji.IsRequireColons()
			<< ", Managed: " << emoji.IsManaged()
			<< ", Animated: " << emoji.IsAnimated()
			<< ", Available: " << emoji.IsAvailable();
		return os;
	}
}
