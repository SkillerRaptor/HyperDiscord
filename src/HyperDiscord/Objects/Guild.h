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
		Snowflake m_Id;
		std::string m_Name;
		std::string m_Icon;
		std::string m_Splash;
		std::string m_DiscoverySplash;
		bool m_Owner;
		Snowflake m_OwnerId;
		std::string m_Permissions;
		VoiceRegion m_Region;
		Snowflake m_AfkChannelId;
		uint32_t m_AfkTimeout;
		bool m_WidgetEnabled;
		Snowflake m_WidgetChannelId;
		VerificationLevel m_VerificationLevel;
		MessageNotificationLevel m_DefaultMessageNotifications;
		ContentFilterLevel m_ExplicitContentFilter;
		std::vector<Role> m_Roles;
		std::vector<Emoji> m_Emojis;
		std::vector<GuildFeatures> m_Features;
		MFALevel m_MfaLevel;
		Snowflake m_ApplicationId;
		Snowflake m_SystemChannelId;
		SystemChannelFlags m_SystemChannelFlags;
		Snowflake m_RulesChannelId;
		Iso8601 m_JoinedAt;
		bool m_Large;
		bool m_Unavailable;
		uint64_t m_MemberCount;
		std::vector<VoiceState> m_VoiceStates;
		std::vector<GuildMember> m_Members;
		std::vector<Channel> m_Channels;
		std::vector<PresenceUpdate> m_Presences;
		uint32_t m_MaxPresences;
		uint32_t m_MaxMembers;
		std::string m_VanityUrlCode;
		std::string m_Description;
		std::string m_Banner;
		PremiumTier m_PremiumTier;
		uint32_t m_PremiumSubscriptionCount;
		std::string m_PreferredLocale;
		Snowflake m_PublicUpdatesChannelId;
		uint32_t m_MaxVideoChannelUsers;
		uint32_t m_ApproximateMemberCount;
		uint32_t m_ApproximatePresenceCount;

	public:
		Guild(Snowflake id, std::string name, std::string icon, std::string splash, std::string discoverySplash, bool owner, Snowflake ownerId, std::string permissions, VoiceRegion region, Snowflake afkChannelId, uint32_t afkTimeout, bool widgetEnabled, Snowflake widgetChannelId, VerificationLevel verificationLevel, MessageNotificationLevel defaultMessageNotifications, ContentFilterLevel explicitContentFilter, std::vector<Role> roles, std::vector<Emoji> emojis, std::vector<GuildFeatures> features, MFALevel mfaLevel, Snowflake applicationId, Snowflake systemChannelId, SystemChannelFlags systemChannelFlags, Snowflake rulesChannelId, Iso8601 joinedAt, bool large, bool unavailable, uint64_t memberCount, std::vector<VoiceState> voiceStates, std::vector<GuildMember> members, std::vector<Channel> channels, std::vector<PresenceUpdate> presences, uint32_t maxPresences, uint32_t maxMembers, std::string vanityUrlCode, std::string description, std::string banner, PremiumTier premiumTier, uint32_t premiumSubscriptionCount, std::string preferredLocale, Snowflake publicUpdatesChannelId, uint32_t maxVideoChannelUsers, uint32_t approximateMemberCount, uint32_t approximatePresenceCount);
	
		void SetId(Snowflake id);
		Snowflake GetId() const;

		void SetName(const std::string& name);
		const std::string& GetName() const;

		void SetIcon(const std::string& icon);
		const std::string& GetIcon() const;

		void SetSplash(const std::string& splash);
		const std::string& GetSplash() const;

		void SetDiscoverySplash(const std::string& discoverySplash);
		const std::string& GetDiscoverySplash() const;

		void SetOwner(bool owner);
		bool IsOwner() const;

		void SetOwnerId(Snowflake ownerId);
		Snowflake GetOwnerId() const;

		void SetPermissions(const std::string& permissions);
		const std::string& GetPermissions() const;

		void SetRegion(VoiceRegion region);
		VoiceRegion GetRegion() const;

		void SetAfkChannelId(Snowflake afkChannelId);
		Snowflake GetAfkChannelId() const;

		void SetAfkTimeout(uint32_t afkTimeout);
		uint32_t GetAfkTimeout() const;

		void SetWidgetEnabled(bool widgetEnabled);
		bool IsWidgetEnabled() const;

		void SetWidgetChannelId(Snowflake widgetChannelId);
		Snowflake GetWidgetChannelId() const;

		void SetVerificationLevel(VerificationLevel verificationLevel);
		VerificationLevel GetVerificationLevel() const;

		void SetDefaultMessageNotifications(MessageNotificationLevel defaultMessageNotification);
		MessageNotificationLevel GetDefaultMessageNotifications() const;

		void SetExplicitContentFilter(ContentFilterLevel explicitContentFilter);
		ContentFilterLevel GetExplicitContentFilter() const;

		void SetRoles(std::vector<Role> roles);
		std::vector<Role> GetRoles() const;

		void SetEmojis(std::vector<Emoji> emojis);
		std::vector<Emoji> GetEmojis() const;

		void SetFeatures(std::vector<GuildFeatures> features);
		std::vector<GuildFeatures> GetFeatures() const;

		void SetMfaLevel(MFALevel mfaLevel);
		MFALevel GetMfaLevel() const;

		void SetApplicationId(Snowflake applicationId);
		Snowflake GetApplicationId() const;

		void SetSystemChannelId(Snowflake systemChannelId);
		Snowflake GetSystemChannelId() const;

		void SetSystemChannelFlags(SystemChannelFlags systemChannelFlags);
		SystemChannelFlags GetSystemChannelFlags() const;

		void SetRulesChannelId(Snowflake rulesChannelId);
		Snowflake GetRulesChannelId() const;

		void SetJoinedAt(Iso8601 joinedAt);
		Iso8601 GetJoinedAt() const;

		void SetLarge(bool large);
		bool IsLarge() const;

		void SetUnavailable(bool unavailable);
		bool IsUnavailable() const;

		void SetMemberCount(uint64_t memberCount);
		uint64_t GetMemberCount() const;

		void SetVoiceStates(std::vector<VoiceState> voiceStates);
		std::vector<VoiceState> GetVoiceStates() const;

		void SetMembers(std::vector<GuildMember> members);
		std::vector<GuildMember> GetMembers() const;

		void SetChannels(std::vector<Channel> channels);
		std::vector<Channel> GetChannels() const;

		void SetPresences(std::vector<PresenceUpdate> presences);
		std::vector<PresenceUpdate> GetPresences() const;

		void SetMaxPresences(uint32_t maxPresences);
		uint32_t GetMaxPresences() const;

		void SetMaxMembers(uint32_t maxMembers);
		uint32_t GetMaxMembers() const;

		void SetVanityUrlCode(const std::string& vanityUrlCode);
		const std::string& GetVanityUrlCode() const;

		void SetDescription(const std::string& description);
		const std::string& GetDescription() const;

		void SetBanner(const std::string& banner);
		const std::string& GetBanner() const;

		void SetPremiumTier(PremiumTier premiumTier);
		PremiumTier GetPremiumTier() const;

		void SetPremiumSubscriptionCount(uint32_t premiumSubscriptionCount);
		uint32_t GetPremiumSubscriptionCount() const;

		void SetPreferredLocale(const std::string& preferredLocale);
		const std::string& GetPreferredLocale() const;

		void SetPublicUpdatesChannelId(Snowflake publicUpdatesChannelId);
		Snowflake GetPublicUpdatesChannelId() const;

		void SetMaxVideoChannelUsers(uint32_t maxVideoChannelUsers);
		uint32_t GetMaxVideoChannelUsers() const;

		void SetApproximateMemberCount(uint32_t approximateMemberCount);
		uint32_t GetApproximateMemberCount() const;

		void SetApproximatePresenceCount(uint32_t approximatePresenceCount);
		uint32_t GetApproximatePresenceCount() const;

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
		os << "Id: " << guild.GetId()
			<< ", Name: " << guild.GetName()
			<< ", Icon: " << guild.GetIcon()
			<< ", Splash: " << guild.GetSplash()
			<< ", Discovery Splash: " << guild.GetDiscoverySplash()
			<< ", Owner: " << guild.IsOwner()
			<< ", Owner Id: " << guild.GetOwnerId()
			<< ", Permissions: " << guild.GetPermissions()
			<< ", Region: " << guild.GetRegion()
			<< ", AFK Channel Id: " << guild.GetAfkChannelId()
			<< ", AFK Timeout: " << guild.GetAfkTimeout()
			<< ", Widget Enabled: " << guild.IsWidgetEnabled()
			<< ", Widget Channel Id: " << guild.GetWidgetChannelId()
			<< ", Verification Level: " << guild.GetVerificationLevel()
			<< ", Default Message Notifications: " << guild.GetDefaultMessageNotifications()
			<< ", Explicit Content Filter: " << guild.GetExplicitContentFilter()
			//<< ", Roles: " << guild.GetRoles()
			//<< ", Emojis: " << guild.GetEmojis()
			//<< ", Features: " << guild.GetFeatures()
			<< ", MFA Level: " << guild.GetMfaLevel()
			<< ", Application Id: " << guild.GetApplicationId()
			<< ", System Channel Id: " << guild.GetSystemChannelId()
			<< ", System Channel Flags: " << guild.GetSystemChannelFlags()
			<< ", Rules Channel Id: " << guild.GetRulesChannelId()
			//<< ", Joined At: " << guild.GetJoinedAt()
			<< ", Large: " << guild.IsLarge()
			<< ", Unavailable: " << guild.IsUnavailable()
			<< ", Member Count: " << guild.GetMemberCount()
			//<< ", Voice States: " << guild.GetVoiceStates()
			//<< ", Members: " << guild.GetMembers()
			//<< ", Channels: " << guild.GetChannels()
			//<< ", Presences: " << guild.GetPresences()
			<< ", Max Presences: " << guild.GetMaxPresences()
			<< ", Max Members: " << guild.GetMaxMembers()
			<< ", Vanity Url Code: " << guild.GetVanityUrlCode()
			<< ", Description: " << guild.GetDescription()
			<< ", Banner: " << guild.GetBanner()
			<< ", Premium Tier: " << guild.GetPremiumTier()
			<< ", Premium Subscription Count: " << guild.GetPremiumSubscriptionCount()
			<< ", Preferred Locale: " << guild.GetPreferredLocale()
			<< ", Public Updates Channel Id: " << guild.GetPublicUpdatesChannelId()
			<< ", Max Video Channel Users: " << guild.GetMaxVideoChannelUsers()
			<< ", Approximate Member Count: " << guild.GetApproximateMemberCount()
			<< ", Approximate Presence Count: " << guild.GetApproximatePresenceCount();
		return os;
	}
}
