#pragma once

#include <string>
#include <vector>

#include "Snowflake.h"
#include "VoiceRegion.h"
#include "Utilities/Iso8601.h"

namespace HyperDiscord
{
	/* https://discord.com/developers/docs/resources/guild#guild-object-verification-level */
	enum class VerificationLevel
	{
		NONE = 0,
		LOW,
		MEDIUM,
		HIGH,
		VERY_HIGH
	};

	/* https://discord.com/developers/docs/resources/guild#guild-object-guild-structure */
	class Guild
	{
	private:
		//Snowflake m_Id;
		std::string m_Name;
		std::string m_Icon;
		std::string m_Splash;
		std::string m_DiscoverySplash;
		bool m_Owner;
		//Snowflake m_OwnerId;
		std::string m_Permissions;
		VoiceRegion m_Region;
		//Snowflake m_AfkChannelId;
		uint32_t m_AfkTimeout;
		bool m_WidgetEnabled;
		//Snowflake m_WidgetChannelId;
		VerificationLevel m_VerificationLevel;

	public:
		Guild();
		~Guild();
	};
}
