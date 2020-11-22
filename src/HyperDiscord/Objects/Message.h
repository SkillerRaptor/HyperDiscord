#pragma once

#include <string>
#include <vector>

#include "Channel.h"
#include "Emoji.h"
#include "GuildMember.h"
#include "Snowflake.h"
#include "Role.h"
#include "User.h"
#include "Utilities/Iso8601.h"

namespace HyperDiscord
{
	/* https://discord.com/developers/docs/resources/channel#channel-mention-object-channel-mention-structure */
	struct ChannelMention
	{
		Snowflake Id;
		Snowflake GuildId;
		ChannelType Type;
		std::string Name;
	};

	/* https://discord.com/developers/docs/resources/channel#attachment-object-attachment-structure */
	struct Attachment
	{
		Snowflake Id;
		std::string Filename;
		uint32_t Size;
		std::string Url;
		std::string ProxyUrl;
		uint32_t Width;
		uint32_t Heigh;
	};

	/* https://discord.com/developers/docs/resources/channel#embed-object-embed-footer-structure */
	struct EmbedFooter
	{
		std::string Text;
		std::string IconUrl;
		std::string ProxyIconUrl;
	};

	/* https://discord.com/developers/docs/resources/channel#embed-object-embed-image-structure */
	struct EmbedImage
	{
		std::string Url;
		std::string ProxyUrl;
		uint32_t Width;
		uint32_t Height;
	};

	/* https://discord.com/developers/docs/resources/channel#embed-object-embed-thumbnail-structure */
	struct EmbedThumbnail
	{
		std::string Url;
		std::string ProxyUrl;
		uint32_t Width;
		uint32_t Height;
	};

	/* https://discord.com/developers/docs/resources/channel#embed-object-embed-video-structure */
	struct EmbedVideo
	{
		std::string Url;
		uint32_t Width;
		uint32_t Height;
	};

	/* https://discord.com/developers/docs/resources/channel#embed-object-embed-provider-structure */
	struct EmbedProvider
	{
		std::string Name;
		std::string Url;
	};

	/* https://discord.com/developers/docs/resources/channel#embed-object-embed-author-structure */
	struct EmbedAuthor
	{
		std::string Name;
		std::string Url;
		std::string IconUrl;
		std::string ProxyIconUrl;
	};

	/* https://discord.com/developers/docs/resources/channel#embed-object-embed-field-structure */
	struct EmbedField
	{
		std::string Name;
		std::string Value;
		bool Inline;
	};

	/* https://discord.com/developers/docs/resources/channel#embed-object-embed-structure */
	struct Embed
	{
		std::string Title;
		std::string Type;
		std::string Description;
		std::string Url;
		Iso8601 Timestamp;
		uint32_t Color;
		EmbedFooter Footer;
		EmbedImage Image;
		EmbedThumbnail Thumnnail;
		EmbedVideo Video;
		EmbedProvider Provider;
		EmbedAuthor Author;
		std::vector<EmbedField> Fields;
	};

	/* https://discord.com/developers/docs/resources/channel#reaction-object */
	struct Reaction
	{
		uint32_t Count;
		bool Me;
		Emoji emoji;
	};

	/* https://discord.com/developers/docs/resources/channel#message-object-message-types */
	enum class MessageType
	{
		DEFAULT = 0,
		RECIPENT_ADD,
		RECIPENT_REMOVE,
		CALL,
		CHANNEL_NAME_CHANGE,
		CHANNEL_ICON_CHANGE,
		CHANNEL_PINNED_MESSAGE,
		GUILD_MEMBER_JOIN,
		USER_PREMIUM_GUILD_SUBSCRIPTION,
		USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_1,
		USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_2,
		USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_3,
		CHANNEL_FOLLOW_ADD,
		GUILD_DISCOVERY_DISQUALIFIED,
		GUILD_DISCOVERY_REQUALIFIED,
		REPLY
	};

	/* https://discord.com/developers/docs/resources/channel#message-object-message-activity-types */
	enum class MessageActivityType
	{
		JOIN = 0,
		SPECTATE,
		LISTEN,
		JOIN_REQUEST
	};

	/* https://discord.com/developers/docs/resources/channel#message-object-message-activity-structure */
	struct MessageActivity
	{
		MessageActivityType Type;
		std::string PartyId;
	};

	/* https://discord.com/developers/docs/resources/channel#message-object-message-application-structure */
	struct MessageApplication
	{
		Snowflake Id;
		std::string CoverImage;
		std::string Description;
		std::string Icon;
		std::string Name;
	};

	/* https://discord.com/developers/docs/resources/channel#message-object-message-reference-structure */
	struct MessageReference
	{
		Snowflake MessageId;
		Snowflake ChannelId;
		Snowflake GuildId;
	};

	/* https://discord.com/developers/docs/resources/channel#message-object-message-sticker-format-types */
	enum class MessageStickerType
	{
		PNG = 0,
		APNG,
		LOTTIE
	};

	/* https://discord.com/developers/docs/resources/channel#message-object-message-sticker-structure */
	struct MessageSticker
	{
		Snowflake Id;
		Snowflake PackId;
		std::string Name;
		std::string Description;
		std::string Tags;
		std::string Asset;
		std::string PreviewAsset;
		MessageStickerType FormatType;
	};

	/* https://discord.com/developers/docs/resources/channel#message-object */
	struct Message
	{
		Snowflake Id;
		Snowflake ChannelId;
		Snowflake GuildId;
		User Author;
		GuildMember Member;
		std::string Content;
		Iso8601 Timestamp;
		Iso8601 EditedTimestamp;
		bool TTS;
		bool MentionEveryone;
		std::vector<User> Mentions;
		std::vector<Role> MentionRoles;
		std::vector<ChannelMention> MentionChannels;
		std::vector<Attachment> Attachments;
		std::vector<Embed> Embeds;
		std::vector<Reaction> Reactions;
		std::string Nonce;
		bool Pinned;
		Snowflake WebhookId;
		MessageType Type;
		MessageActivity Activity;
		MessageApplication Application;
		MessageReference MessageReference;
		uint32_t Flags;
		std::vector<MessageSticker> Stickers;
		Message* ReferencedMessage;
	};
}
