#include "Guild.h"

namespace HyperDiscord
{
	Guild::Guild(Snowflake id, std::string name, std::string icon, std::string splash, std::string discoverySplash, bool owner, Snowflake ownerId, std::string permissions, VoiceRegion region, Snowflake afkChannelId, uint32_t afkTimeout, bool widgetEnabled, Snowflake widgetChannelId, VerificationLevel verificationLevel, MessageNotificationLevel defaultMessageNotifications, ContentFilterLevel explicitContentFilter, std::vector<Role> roles, std::vector<Emoji> emojis, std::vector<GuildFeatures> features, MFALevel mfaLevel, Snowflake applicationId, Snowflake systemChannelId, SystemChannelFlags systemChannelFlags, Snowflake rulesChannelId, Iso8601 joinedAt, bool large, bool unavailable, uint64_t memberCount, std::vector<VoiceState> voiceStates, std::vector<GuildMember> members, std::vector<Channel> channels, std::vector<PresenceUpdate> presences, uint32_t maxPresences, uint32_t maxMembers, std::string vanityUrlCode, std::string description, std::string banner, PremiumTier premiumTier, uint32_t premiumSubscriptionCount, std::string preferredLocale, Snowflake publicUpdatesChannelId, uint32_t maxVideoChannelUsers, uint32_t approximateMemberCount, uint32_t approximatePresenceCount)
		: m_Id(id), m_Name(name), m_Icon(icon), m_Splash(splash), m_DiscoverySplash(discoverySplash), m_Owner(owner), m_OwnerId(m_OwnerId), m_Permissions(permissions), m_Region(region), m_AfkChannelId(afkChannelId), m_AfkTimeout(afkTimeout), m_WidgetEnabled(widgetEnabled), m_WidgetChannelId(widgetChannelId), m_VerificationLevel(verificationLevel), m_DefaultMessageNotifications(defaultMessageNotifications), m_ExplicitContentFilter(explicitContentFilter), m_Roles(roles), m_Emojis(emojis), m_Features(features),  m_MfaLevel(mfaLevel), m_ApplicationId(applicationId), m_SystemChannelId(systemChannelId), m_SystemChannelFlags(systemChannelFlags), m_RulesChannelId(rulesChannelId), m_JoinedAt(joinedAt), m_Large(large), m_Unavailable(unavailable), m_MemberCount(memberCount), m_VoiceStates(voiceStates), m_Members(members), m_Channels(channels), m_Presences(presences), m_MaxPresences(maxPresences), m_MaxMembers(maxMembers), m_VanityUrlCode(vanityUrlCode), m_Description(description), m_Banner(banner), m_PremiumTier(premiumTier), m_PremiumSubscriptionCount(premiumSubscriptionCount), m_PreferredLocale(preferredLocale), m_PublicUpdatesChannelId(publicUpdatesChannelId), m_MaxVideoChannelUsers(maxVideoChannelUsers), m_ApproximateMemberCount(approximateMemberCount), m_ApproximatePresenceCount(approximatePresenceCount)
	{
	}

	void Guild::SetId(Snowflake id)
	{
		m_Id = id;
	}

	Snowflake Guild::GetId() const
	{
		return m_Id;
	}

	void Guild::SetName(const std::string& name)
	{
		m_Name = name;
	}

	const std::string& Guild::GetName() const
	{
		return m_Name;
	}

	void Guild::SetIcon(const std::string& icon)
	{
		m_Icon = icon;
	}

	const std::string& Guild::GetIcon() const
	{
		return m_Icon;
	}

	void Guild::SetSplash(const std::string& splash)
	{
		m_Splash = splash;
	}

	const std::string& Guild::GetSplash() const
	{
		return m_Splash;
	}

	void Guild::SetDiscoverySplash(const std::string& discoverySplash)
	{
		m_DiscoverySplash = discoverySplash;
	}

	const std::string& Guild::GetDiscoverySplash() const
	{
		return m_DiscoverySplash;
	}

	void Guild::SetOwner(bool owner)
	{
		m_Owner = owner;
	}

	bool Guild::IsOwner() const
	{
		return m_Owner;
	}

	void Guild::SetOwnerId(Snowflake ownerId)
	{
		m_OwnerId = ownerId;
	}

	Snowflake Guild::GetOwnerId() const
	{
		return m_OwnerId;
	}

	void Guild::SetPermissions(const std::string& permissions)
	{
		m_Permissions = permissions;
	}

	const std::string& Guild::GetPermissions() const
	{
		return m_Permissions;
	}

	void Guild::SetRegion(VoiceRegion region)
	{
		m_Region = region;
	}

	VoiceRegion Guild::GetRegion() const
	{
		return m_Region;
	}

	void Guild::SetAfkChannelId(Snowflake afkChannelId)
	{
		m_AfkChannelId = afkChannelId;
	}

	Snowflake Guild::GetAfkChannelId() const
	{
		return m_AfkChannelId;
	}

	void Guild::SetAfkTimeout(uint32_t afkTimeout)
	{
		m_AfkTimeout = afkTimeout;
	}

	uint32_t Guild::GetAfkTimeout() const
	{
		return m_AfkTimeout;
	}

	void Guild::SetWidgetEnabled(bool widgetEnabled)
	{
		m_WidgetEnabled = widgetEnabled;
	}

	bool Guild::IsWidgetEnabled() const
	{
		return m_WidgetEnabled;
	}

	void Guild::SetWidgetChannelId(Snowflake widgetChannelId)
	{
		m_WidgetChannelId = widgetChannelId;
	}

	Snowflake Guild::GetWidgetChannelId() const
	{
		return m_WidgetChannelId;
	}
	
	void Guild::SetVerificationLevel(VerificationLevel verificationLevel)
	{
		m_VerificationLevel = verificationLevel;
	}
	
	VerificationLevel Guild::GetVerificationLevel() const
	{
		return m_VerificationLevel;
	}
	
	void Guild::SetDefaultMessageNotifications(MessageNotificationLevel defaultMessageNotification)
	{
		m_DefaultMessageNotifications = defaultMessageNotification;
	}

	MessageNotificationLevel Guild::GetDefaultMessageNotifications() const
	{
		return m_DefaultMessageNotifications;
	}

	void Guild::SetExplicitContentFilter(ContentFilterLevel explicitContentFilter)
	{
		m_ExplicitContentFilter = explicitContentFilter;
	}

	ContentFilterLevel Guild::GetExplicitContentFilter() const
	{
		return m_ExplicitContentFilter;
	}

	void Guild::SetRoles(std::vector<Role> roles)
	{
		m_Roles = roles;
	}

	std::vector<Role> Guild::GetRoles() const
	{
		return m_Roles;
	}

	void Guild::SetEmojis(std::vector<Emoji> emojis)
	{
		m_Emojis = emojis;
	}

	std::vector<Emoji> Guild::GetEmojis() const
	{
		return m_Emojis;
	}

	void Guild::SetFeatures(std::vector<GuildFeatures> features)
	{
		m_Features = features;
	}

	std::vector<GuildFeatures> Guild::GetFeatures() const
	{
		return m_Features;
	}

	void Guild::SetMfaLevel(MFALevel mfaLevel)
	{
		m_MfaLevel = mfaLevel;
	}

	MFALevel Guild::GetMfaLevel() const
	{
		return m_MfaLevel;
	}

	void Guild::SetApplicationId(Snowflake applicationId)
	{
		m_ApplicationId = applicationId;
	}

	Snowflake Guild::GetApplicationId() const
	{
		return m_ApplicationId;
	}

	void Guild::SetSystemChannelId(Snowflake systemChannelId)
	{
		m_SystemChannelId = systemChannelId;
	}

	Snowflake Guild::GetSystemChannelId() const
	{
		return m_SystemChannelId;
	}

	void Guild::SetSystemChannelFlags(SystemChannelFlags systemChannelFlags)
	{
		m_SystemChannelFlags = systemChannelFlags;
	}

	SystemChannelFlags Guild::GetSystemChannelFlags() const
	{
		return m_SystemChannelFlags;
	}

	void Guild::SetRulesChannelId(Snowflake rulesChannelId)
	{
		m_RulesChannelId = rulesChannelId;
	}

	Snowflake Guild::GetRulesChannelId() const
	{
		return m_RulesChannelId;
	}

	void Guild::SetJoinedAt(Iso8601 joinedAt)
	{
		m_JoinedAt = joinedAt;
	}

	Iso8601 Guild::GetJoinedAt() const
	{
		return m_JoinedAt;
	}

	void Guild::SetLarge(bool large)
	{
		m_Large = large;
	}

	bool Guild::IsLarge() const
	{
		return m_Large;
	}

	void Guild::SetUnavailable(bool unavailable)
	{
		m_Unavailable = unavailable;
	}

	bool Guild::IsUnavailable() const
	{
		return m_Unavailable;
	}

	void Guild::SetMemberCount(uint64_t memberCount)
	{
		m_MemberCount = memberCount;
	}

	uint64_t Guild::GetMemberCount() const
	{
		return m_MemberCount;
	}

	void Guild::SetVoiceStates(std::vector<VoiceState> voiceStates)
	{
		m_VoiceStates = voiceStates;
	}

	std::vector<VoiceState> Guild::GetVoiceStates() const
	{
		return m_VoiceStates;
	}

	void Guild::SetMembers(std::vector<GuildMember> members)
	{
		m_Members = members;
	}

	std::vector<GuildMember> Guild::GetMembers() const
	{
		return m_Members;
	}

	void Guild::SetChannels(std::vector<Channel> channels)
	{
		m_Channels = channels;
	}

	std::vector<Channel> Guild::GetChannels() const
	{
		return m_Channels;
	}

	void Guild::SetPresences(std::vector<PresenceUpdate> presences)
	{
		m_Presences = presences;
	}

	std::vector<PresenceUpdate> Guild::GetPresences() const
	{
		return m_Presences;
	}

	void Guild::SetMaxPresences(uint32_t maxPresences)
	{
		m_MaxPresences = maxPresences;
	}

	uint32_t Guild::GetMaxPresences() const
	{
		return m_MaxPresences;
	}

	void Guild::SetMaxMembers(uint32_t maxMembers)
	{
		m_MaxMembers = maxMembers;
	}

	uint32_t Guild::GetMaxMembers() const
	{
		return m_MaxMembers;
	}

	void Guild::SetVanityUrlCode(const std::string& vanityUrlCode)
	{
		m_VanityUrlCode = vanityUrlCode;
	}

	const std::string& Guild::GetVanityUrlCode() const
	{
		return m_VanityUrlCode;
	}

	void Guild::SetDescription(const std::string& description)
	{
		m_Description = description;
	}

	const std::string& Guild::GetDescription() const
	{
		return m_Description;
	}

	void Guild::SetBanner(const std::string& banner)
	{
		m_Banner = banner;
	}

	const std::string& Guild::GetBanner() const
	{
		return m_Banner;
	}

	void Guild::SetPremiumTier(PremiumTier premiumTier)
	{
		m_PremiumTier = premiumTier;
	}

	PremiumTier Guild::GetPremiumTier() const
	{
		return m_PremiumTier;
	}

	void Guild::SetPremiumSubscriptionCount(uint32_t premiumSubscriptionCount)
	{
		m_PremiumSubscriptionCount = premiumSubscriptionCount;
	}

	uint32_t Guild::GetPremiumSubscriptionCount() const
	{
		return m_PremiumSubscriptionCount;
	}

	void Guild::SetPreferredLocale(const std::string& preferredLocale)
	{
		m_PreferredLocale = preferredLocale;
	}

	const std::string& Guild::GetPreferredLocale() const
	{
		return m_PreferredLocale;
	}

	void Guild::SetPublicUpdatesChannelId(Snowflake publicUpdatesChannelId)
	{
		m_PublicUpdatesChannelId = publicUpdatesChannelId;
	}

	Snowflake Guild::GetPublicUpdatesChannelId() const
	{
		return m_PublicUpdatesChannelId;
	}

	void Guild::SetMaxVideoChannelUsers(uint32_t maxVideoChannelUsers)
	{
		m_MaxVideoChannelUsers = maxVideoChannelUsers;
	}

	uint32_t Guild::GetMaxVideoChannelUsers() const
	{
		return m_MaxVideoChannelUsers;
	}

	void Guild::SetApproximateMemberCount(uint32_t approximateMemberCount)
	{
		m_ApproximateMemberCount = approximateMemberCount;
	}

	uint32_t Guild::GetApproximateMemberCount() const
	{
		return m_ApproximateMemberCount;
	}

	void Guild::SetApproximatePresenceCount(uint32_t approximatePresenceCount)
	{
		m_ApproximatePresenceCount = approximatePresenceCount;
	}

	uint32_t Guild::GetApproximatePresenceCount() const
	{
		return m_ApproximatePresenceCount;
	}
}
