#pragma once

#include <string>

#include "Snowflake.h"

namespace HyperDiscord
{
	/* https://discord.com/developers/docs/resources/user#user-object-user-flags */
	enum class UserFlags
	{
		NONE = 0,
		DISCORD_EMPLOYEE = 1 << 0,
		PARTNERED_SERVER_OWNER = 1 << 1,
		HYPESQUAD_EVENTS = 1 << 2,
		BUG_HUNTER_LEVEL_1 = 1 << 3,
		HOUSE_BRAVERY = 1 << 6,
		HOUSE_BRILLIANCE = 1 << 7,
		HOUSE_BALANCE = 1 << 8,
		EARLY_SUPPORTER = 1 << 9,
		TEAM_USER = 1 << 10,
		SYSTEM = 1 << 12,
		BUG_HUNTER_LEVEL_2 = 1 << 14,
		VERIFIED_BOT = 1 << 16,
		EARLY_VERIFIED_BOT_DEVELOPER = 1 << 17
	};

	/* https://discord.com/developers/docs/resources/user#user-object-premium-types */
	enum class PremiumType
	{
		NONE = 0,
		NITRO_CLASSIC,
		NITRO
	};

	/* https://discord.com/developers/docs/resources/user#user-object-user-structure */
	class User
	{
	private:
		//Snowflake m_Id;
		std::string m_Username;
		std::string m_Discriminator;
		std::string m_Avatar;
		bool m_Bot;
		bool m_System;
		bool m_MfaEnabled;
		std::string m_Locale;
		bool m_Verified;
		std::string m_Email;
		uint32_t m_Flags;
		PremiumType m_PremiumType;
		uint32_t m_PublicFlags;

	public:
		User();
		~User();
	};
}
