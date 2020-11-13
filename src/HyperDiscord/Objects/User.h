#pragma once

#include <iostream>
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
	struct User
	{
		Snowflake Id;
		std::string Username;
		std::string Discriminator;
		std::string Avatar;
		bool Bot;
		bool System;
		bool MfaEnabled;
		std::string Locale;
		bool Verified;
		std::string Email;
		uint32_t Flags;
		PremiumType PremiumType;
		uint32_t PublicFlags;

		friend std::ostream& operator<<(std::ostream& os, const User& user);
	};

	inline std::ostream& operator<<(std::ostream& os, const PremiumType& premiumType)
	{
		switch (premiumType) 
		{
		case PremiumType::NONE:
			os << "None";
			break;
		case PremiumType::NITRO_CLASSIC:
			os << "Nitro Classic";
			break;
		case PremiumType::NITRO:
			os << "Nitro";
			break;
		}
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const User& user)
	{
		os << "Id: " << user.Id
			<< ", Username: " << user.Username
			<< ", Discriminator: " << user.Discriminator
			<< ", Avatar: " << user.Avatar
			<< ", Bot: " << user.Bot
			<< ", System: " << user.System
			<< ", Enabled: " << user.MfaEnabled
			<< ", Locale: " << user.Locale
			<< ", Verified: " << user.Verified
			<< ", Email: " << user.Email
			<< ", Flags: " << user.Flags
			<< ", Premium Type: " << user.PremiumType
			<< ", Public Flags: " << user.PublicFlags;
		return os;
	}
}
