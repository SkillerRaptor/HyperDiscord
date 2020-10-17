#include "User.h"

namespace HyperDiscord
{
	User::User(Snowflake id, const std::string& username, const std::string& discriminator, const std::string& avatar, bool bot, bool system, bool mfaEnabled, const std::string& locale, bool verified, const std::string& email, uint32_t flags, PremiumType premiumType, uint32_t publicFlags)
		: m_Id(id), m_Username(username), m_Discriminator(discriminator), m_Avatar(avatar), m_Bot(bot), m_System(system), m_MfaEnabled(mfaEnabled), m_Locale(locale), m_Verified(verified), m_Email(email), m_Flags(flags), m_PremiumType(premiumType), m_PublicFlags(publicFlags)
	{
	}

	void User::SetId(Snowflake id)
	{
		m_Id = id;
	}

	Snowflake User::GetId() const
	{
		return m_Id;
	}

	void User::SetUsername(const std::string& username)
	{
		m_Username = username;
	}

	const std::string& User::GetUsername() const
	{
		return m_Username;
	}

	void User::SetDiscriminator(const std::string& discriminator)
	{
		m_Discriminator = discriminator;
	}

	const std::string& User::GetDiscriminator() const
	{
		return m_Discriminator;
	}

	void User::SetAvatar(const std::string& avatar)
	{
		m_Avatar = avatar;
	}

	const std::string& User::GetAvatar() const
	{
		return m_Avatar;
	}

	void User::SetBot(bool bot)
	{
		m_Bot = bot;
	}

	bool User::IsBot() const
	{
		return m_Bot;
	}

	void User::SetSystem(bool system)
	{
		m_System = system;
	}

	bool User::IsSystem() const
	{
		return m_System;
	}

	void User::SetMfaEnabled(bool mfaEnabled)
	{
		m_MfaEnabled = mfaEnabled;
	}

	bool User::IsMfaEnabled() const
	{
		return m_MfaEnabled;
	}

	void User::SetLocale(const std::string& locale)
	{
		m_Locale = locale;
	}

	const std::string& User::GetLocale() const
	{
		return m_Locale;
	}

	void User::SetVerified(bool verified)
	{
		m_Verified = verified;
	}

	bool User::IsVerified() const
	{
		return m_Verified;
	}

	void User::SetEmail(const std::string& email)
	{
		m_Email = email;
	}

	const std::string& User::GetEmail() const
	{
		return m_Email;
	}

	void User::SetFlags(uint32_t flags)
	{
		m_Flags = flags;
	}

	uint32_t User::GetFlags() const
	{
		return m_Flags;
	}

	void User::SetPremiumType(PremiumType premiumType)
	{
		m_PremiumType = premiumType;
	}

	PremiumType User::GetPremiumType() const
	{
		return m_PremiumType;
	}

	void User::SetPublicFlags(uint32_t publicFlags)
	{
		m_PublicFlags = publicFlags;
	}

	uint32_t User::GetPublicFlags() const
	{
		return m_PublicFlags;
	}
}
