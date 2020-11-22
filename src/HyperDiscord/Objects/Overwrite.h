#pragma once

#ifndef _WIN32
#error HyperDiscord is only supporting Windows in the moment
#endif

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
	struct Overwrite
	{
		Snowflake Id;
		OverwriteType Type;
		std::string Allow;
		std::string Deny;

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
		os << "Id: " << overwrite.Id
			<< ", Type: " << overwrite.Type
			<< ", Allow: " << overwrite.Allow
			<< ", Deny: " << overwrite.Deny;
		return os;
	}
}
