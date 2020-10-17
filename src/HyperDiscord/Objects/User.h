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
	class User
	{
	private:
		Snowflake m_Id;
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
		User(Snowflake id, const std::string& username, const std::string& discriminator, const std::string& avatar, bool bot, bool system, bool mfaEnabled, const std::string& locale, bool verified, const std::string& email, uint32_t flags, PremiumType premiumType,uint32_t publicFlags);

		void SetId(Snowflake id);
		Snowflake GetId() const;

		void SetUsername(const std::string& username);
		const std::string& GetUsername() const;

		void SetDiscriminator(const std::string& discriminator);
		const std::string& GetDiscriminator() const;

		void SetAvatar(const std::string& avatar);
		const std::string& GetAvatar() const;

		void SetBot(bool bot);
		bool IsBot() const;

		void SetSystem(bool system);
		bool IsSystem() const;

		void SetMfaEnabled(bool mfaEnabled);
		bool IsMfaEnabled() const;

		void SetLocale(const std::string& locale);
		const std::string& GetLocale() const;

		void SetVerified(bool verified);
		bool IsVerified() const;

		void SetEmail(const std::string& email);
		const std::string& GetEmail() const;

		void SetFlags(uint32_t flags);
		uint32_t GetFlags() const;

		void SetPremiumType(PremiumType premiumType);
		PremiumType GetPremiumType() const;

		void SetPublicFlags(uint32_t publicFlags);
		uint32_t GetPublicFlags() const;

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
		os << "Id: " << user.GetId()
			<< ", Username: " << user.GetUsername()
			<< ", Discriminator: " << user.GetDiscriminator()
			<< ", Avatar: " << user.GetAvatar()
			<< ", Bot: " << user.IsBot()
			<< ", System: " << user.IsSystem()
			<< ", Enabled: " << user.IsMfaEnabled()
			<< ", Locale: " << user.GetLocale()
			<< ", Verified: " << user.IsVerified()
			<< ", Email: " << user.GetEmail()
			<< ", Flags: " << user.GetFlags()
			<< ", Premium Type: " << user.GetPremiumType()
			<< ", Public Flags: " << user.GetPublicFlags();
		return os;
	}
}
