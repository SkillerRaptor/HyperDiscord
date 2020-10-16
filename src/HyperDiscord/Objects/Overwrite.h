#pragma once

#include <string>

#include "Snowflake.h"

namespace HyperDiscord
{
	enum class OverwriteType
	{
		ROLE = 0,
		MEMBER
	};

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
		std::string GetAllow() const;

		void SetDeny(const std::string& deny);
		std::string GetDeny() const;
	};
}
