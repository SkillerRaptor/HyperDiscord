#pragma once

#include <string>
#include <vector>

#include "Channel.h"
#include "Emoji.h"
#include "GuildMember.h"
#include "Role.h"
#include "Snowflake.h"
#include "VoiceRegion.h"
#include "VoiceState.h"
#include "Networking/Gateway/PresenceUpdate.h"
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

	/* https://discord.com/developers/docs/resources/guild#guild-object-default-message-notification-level */
	enum class MessageNotificationLevel
	{
		ALL_MESSAGES = 0,
		ONLY_MENTIONS
	};

	/* https://discord.com/developers/docs/resources/guild#guild-object-explicit-content-filter-level */
	enum class ContentFilterLevel
	{
		DISABLED = 0,
		MEMBERS_WITHOUT_ROLES,
		ALL_MEMBERS
	};

	/* https://discord.com/developers/docs/resources/guild#guild-object-guild-features */
	enum class GuildFeatures
	{
		INVITE_SPLASH,
		VIP_REGIONS,
		VANITY_URL,
		VERIFIED,
		PARTNERED,
		PUBLIC,
		COMMERCE,
		NEWS,
		DISCOVERABLE,
		FEATURABLE,
		ANIMATED_ICON,
		BANNER,
		PUBLIC_DISABLED,
		WELCOME_SCREEN_ENABLED
	};

	/* https://discord.com/developers/docs/resources/guild#guild-object-mfa-level */
	enum class MFALevel
	{
		NONE = 0,
		ELEVATED
	};

	/* https://discord.com/developers/docs/resources/guild#guild-object-system-channel-flags */
	enum class SystemChannelFlags
	{
		SUPPRESS_JOIN_NOTIFICATIONS = 1 << 0,
		SUPPRESS_PREMIUM_SUBSCRIPTIONS = 1 << 1
	};

	/* https://discord.com/developers/docs/resources/guild#guild-object-premium-tier */
	enum class PremiumTier
	{
		NONE = 0,
		TIER_1,
		TIER_2,
		TIER_3
	};

	/* https://discord.com/developers/docs/resources/guild#guild-object-guild-structure */
	class Guild
	{
	private:
		Snowflake Id;
		std::string Name;
		std::string Icon;
		std::string Splash;
		std::string DiscoverySplash;
		bool Owner;
		Snowflake OwnerId;
		std::string Permissions;
		VoiceRegion Region;
		Snowflake AfkChannelId;
		uint32_t AfkTimeout;
		bool WidgetEnabled;
		Snowflake WidgetChannelId;
		VerificationLevel VerificationLevel;
		MessageNotificationLevel DefaultMessageNotifications;
		ContentFilterLevel ExplicitContentFilter;
		std::vector<Role> Roles;
		std::vector<Emoji> Emojis;
		std::vector<GuildFeatures> Features;
		MFALevel MfaLevel;
		Snowflake ApplicationId;
		Snowflake SystemChannelId;
		SystemChannelFlags SystemChannelFlags;
		Snowflake RulesChannelId;
		Iso8601 JoinedAt;
		bool Large;
		bool Unavailable;
		uint64_t MemberCount;
		std::vector<VoiceState> VoiceStates;
		std::vector<GuildMember> Members;
		std::vector<Channel> Channels;
		std::vector<PresenceUpdate> Presences;
		uint32_t MaxPresences;
		uint32_t MaxMembers;
		std::string VanityUrlCode;
		std::string Description;
		std::string Banner;
		PremiumTier PremiumTier;
		uint32_t PremiumSubscriptionCount;
		std::string PreferredLocale;
		Snowflake PublicUpdatesChannelId;
		uint32_t MaxVideoChannelUsers;
		uint32_t ApproximateMemberCount;
		uint32_t ApproximatePresenceCount;

		friend std::ostream& operator<<(std::ostream& os, const Guild& guild);
	};

	inline std::ostream& operator<<(std::ostream& os, const VerificationLevel& verificationLevel)
	{
		switch (verificationLevel)
		{
		case VerificationLevel::NONE:
			os << "None";
			break;
		case VerificationLevel::LOW:
			os << "Low";
			break;
		case VerificationLevel::MEDIUM:
			os << "Medium";
			break;
		case VerificationLevel::HIGH:
			os << "High";
			break;
		case VerificationLevel::VERY_HIGH:
			os << "Very High";
			break;
		}
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const MessageNotificationLevel& messageNotificationLevel)
	{
		switch (messageNotificationLevel)
		{
		case MessageNotificationLevel::ALL_MESSAGES:
			os << "All Messages";
			break;
		case MessageNotificationLevel::ONLY_MENTIONS:
			os << "Only Mentions";
			break;
		}
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const ContentFilterLevel& contentFilterLevel)
	{
		switch (contentFilterLevel)
		{
		case ContentFilterLevel::DISABLED:
			os << "Disabled";
			break;
		case ContentFilterLevel::MEMBERS_WITHOUT_ROLES:
			os << "Members without Roles";
			break;
		case ContentFilterLevel::ALL_MEMBERS:
			os << "All Members";
			break;
		}
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const GuildFeatures& guildFeatures)
	{
		switch (guildFeatures)
		{
		case GuildFeatures::INVITE_SPLASH:
			os << "Invite Splash";
			break;
		case GuildFeatures::VIP_REGIONS:
			os << "VIP Regions";
			break;
		case GuildFeatures::VANITY_URL:
			os << "Vanity Url";
			break;
		case GuildFeatures::VERIFIED:
			os << "Verified";
			break;
		case GuildFeatures::PARTNERED:
			os << "Partnered";
			break;
		case GuildFeatures::PUBLIC:
			os << "Public";
			break;
		case GuildFeatures::COMMERCE:
			os << "Commerce";
			break;
		case GuildFeatures::NEWS:
			os << "News";
			break;
		case GuildFeatures::DISCOVERABLE:
			os << "Discoverable";
			break;
		case GuildFeatures::FEATURABLE:
			os << "Featurable";
			break;
		case GuildFeatures::ANIMATED_ICON:
			os << "Animated Icon";
			break;
		case GuildFeatures::BANNER:
			os << "Banner";
			break;
		case GuildFeatures::PUBLIC_DISABLED:
			os << "Public Disabled";
			break;
		case GuildFeatures::WELCOME_SCREEN_ENABLED:
			os << "Welcome Screen Enabled";
			break;
		}
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const MFALevel& mfaLevel)
	{
		switch (mfaLevel)
		{
		case MFALevel::NONE:
			os << "None";
			break;
		case MFALevel::ELEVATED:
			os << "Elevated";
			break;
		}
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const SystemChannelFlags& systemChannelFlags)
	{
		switch (systemChannelFlags)
		{
		case SystemChannelFlags::SUPPRESS_JOIN_NOTIFICATIONS:
			os << "Suppress Join Notifications";
			break;
		case SystemChannelFlags::SUPPRESS_PREMIUM_SUBSCRIPTIONS:
			os << "Suppress Premium Subscriptions";
			break;
		}
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const PremiumTier& premiumTier)
	{
		switch (premiumTier)
		{
		case PremiumTier::NONE:
			os << "None";
			break;
		case PremiumTier::TIER_1:
			os << "Tier 1";
			break;
		case PremiumTier::TIER_2:
			os << "Tier 2";
			break;
		case PremiumTier::TIER_3:
			os << "Tier 3";
			break;
		}
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const Guild& guild)
	{
		os << "Id: " << guild.Id
			<< ", Name: " << guild.Name
			<< ", Icon: " << guild.Icon
			<< ", Splash: " << guild.Splash
			<< ", Discovery Splash: " << guild.DiscoverySplash
			<< ", Owner: " << guild.Owner
			<< ", Owner Id: " << guild.OwnerId
			<< ", Permissions: " << guild.Permissions
			<< ", Region: " << guild.Region
			<< ", AFK Channel Id: " << guild.AfkChannelId
			<< ", AFK Timeout: " << guild.AfkTimeout
			<< ", Widget Enabled: " << guild.WidgetEnabled
			<< ", Widget Channel Id: " << guild.WidgetChannelId
			<< ", Verification Level: " << guild.VerificationLevel
			<< ", Default Message Notifications: " << guild.DefaultMessageNotifications
			<< ", Explicit Content Filter: " << guild.ExplicitContentFilter
			//<< ", Roles: " << guild.Roles
			//<< ", Emojis: " << guild.Emojis
			//<< ", Features: " << guild.Features
			<< ", MFA Level: " << guild.MfaLevel
			<< ", Application Id: " << guild.ApplicationId
			<< ", System Channel Id: " << guild.SystemChannelId
			<< ", System Channel Flags: " << guild.SystemChannelFlags
			<< ", Rules Channel Id: " << guild.RulesChannelId
			//<< ", Joined At: " << guild.JoinedAt
			<< ", Large: " << guild.Large
			<< ", Unavailable: " << guild.Unavailable
			<< ", Member Count: " << guild.MemberCount
			//<< ", Voice States: " << guild.VoiceStates
			//<< ", Members: " << guild.Members
			//<< ", Channels: " << guild.Channels
			//<< ", Presences: " << guild.Presences
			<< ", Max Presences: " << guild.MaxPresences
			<< ", Max Members: " << guild.MaxMembers
			<< ", Vanity Url Code: " << guild.VanityUrlCode
			<< ", Description: " << guild.Description
			<< ", Banner: " << guild.Banner
			<< ", Premium Tier: " << guild.PremiumTier
			<< ", Premium Subscription Count: " << guild.PremiumSubscriptionCount
			<< ", Preferred Locale: " << guild.PreferredLocale
			<< ", Public Updates Channel Id: " << guild.PublicUpdatesChannelId
			<< ", Max Video Channel Users: " << guild.MaxVideoChannelUsers
			<< ", Approximate Member Count: " << guild.ApproximateMemberCount
			<< ", Approximate Presence Count: " << guild.ApproximatePresenceCount;
		return os;
	}
}
