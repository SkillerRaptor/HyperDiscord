#pragma once

#include <iostream>
#include <string>

#include "Snowflake.h"

namespace HyperDiscord
{
	enum class OverwriteType
	{
		ROLE = 0,
		MEMBER
	};

	/* https://discord.com/developers/docs/resources/channel#overwrite-object-overwrite-structure */
	class Overwrite
	{
	private:
		Snowflake m_Id;
		OverwriteType m_Type;
		std::string m_Allow;
		std::string m_Deny;

	public:
		Overwrite(Snowflake id, OverwriteType type, const std::string& allow, const std::string& deny);

		void SetId(Snowflake id);
		Snowflake GetId() const;

		void SetType(OverwriteType type);
		OverwriteType GetType() const;

		void SetAllow(const std::string& allow);
		const std::string& GetAllow() const;

		void SetDeny(const std::string& deny);
		const std::string& GetDeny() const;

		friend std::ostream& operator<<(std::ostream& os, const Overwrite& overwrite);
	};

	inline std::ostream& operator<<(std::ostream& os, const OverwriteType& overwriteType)
	{
		switch (overwriteType)
		{
		case OverwriteType::ROLE:
			os << "Role";
			break;
		case OverwriteType::MEMBER:
			os << "Member";
			break;
		}
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const Overwrite& overwrite)
	{
		os << "Id: " << overwrite.GetId()
			<< ", Type: " << overwrite.GetType()
			<< ", Allow: " << overwrite.GetAllow()
			<< ", Deny: " << overwrite.GetDeny();
		return os;
	}
}
