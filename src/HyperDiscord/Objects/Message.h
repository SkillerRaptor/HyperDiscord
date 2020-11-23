#pragma once

#ifndef _WIN32
#error HyperDiscord is only supporting Windows in the moment
#endif

#include <iostream>
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

		friend std::ostream& operator<<(std::ostream& os, const ChannelMention& channelMention);
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

		friend std::ostream& operator<<(std::ostream& os, const Attachment& attachment);
	};

	/* https://discord.com/developers/docs/resources/channel#embed-object-embed-footer-structure */
	struct EmbedFooter
	{
		std::string Text;
		std::string IconUrl;
		std::string ProxyIconUrl;

		friend std::ostream& operator<<(std::ostream& os, const EmbedFooter& embedFooter);
	};

	/* https://discord.com/developers/docs/resources/channel#embed-object-embed-image-structure */
	struct EmbedImage
	{
		std::string Url;
		std::string ProxyUrl;
		uint32_t Width;
		uint32_t Height;

		friend std::ostream& operator<<(std::ostream& os, const EmbedImage& embedImage);
	};

	/* https://discord.com/developers/docs/resources/channel#embed-object-embed-thumbnail-structure */
	struct EmbedThumbnail
	{
		std::string Url;
		std::string ProxyUrl;
		uint32_t Width;
		uint32_t Height;

		friend std::ostream& operator<<(std::ostream& os, const EmbedThumbnail& embedThumbnail);
	};

	/* https://discord.com/developers/docs/resources/channel#embed-object-embed-video-structure */
	struct EmbedVideo
	{
		std::string Url;
		uint32_t Width;
		uint32_t Height;

		friend std::ostream& operator<<(std::ostream& os, const EmbedVideo& embedVideo);
	};

	/* https://discord.com/developers/docs/resources/channel#embed-object-embed-provider-structure */
	struct EmbedProvider
	{
		std::string Name;
		std::string Url;

		friend std::ostream& operator<<(std::ostream& os, const EmbedProvider& embedProvider);
	};

	/* https://discord.com/developers/docs/resources/channel#embed-object-embed-author-structure */
	struct EmbedAuthor
	{
		std::string Name;
		std::string Url;
		std::string IconUrl;
		std::string ProxyIconUrl;

		friend std::ostream& operator<<(std::ostream& os, const EmbedAuthor& embedAuthor);
	};

	/* https://discord.com/developers/docs/resources/channel#embed-object-embed-field-structure */
	struct EmbedField
	{
		std::string Name;
		std::string Value;
		bool Inline;

		friend std::ostream& operator<<(std::ostream& os, const EmbedField& embedField);
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

		friend std::ostream& operator<<(std::ostream& os, const Embed& embed);
	};

	/* https://discord.com/developers/docs/resources/channel#reaction-object */
	struct Reaction
	{
		uint32_t Count;
		bool Me;
		Emoji emoji;

		friend std::ostream& operator<<(std::ostream& os, const Reaction& reaction);
	};

	/* https://discord.com/developers/docs/resources/channel#message-object-message-types */
	enum class MessageType
	{
		DEFAULT = 0,
		RECIPIENT_ADD,
		RECIPIENT_REMOVE,
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

		friend std::ostream& operator<<(std::ostream& os, const MessageActivity& messageActivity);
	};

	/* https://discord.com/developers/docs/resources/channel#message-object-message-application-structure */
	struct MessageApplication
	{
		Snowflake Id;
		std::string CoverImage;
		std::string Description;
		std::string Icon;
		std::string Name;

		friend std::ostream& operator<<(std::ostream& os, const MessageApplication& messageApplication);
	};

	/* https://discord.com/developers/docs/resources/channel#message-object-message-reference-structure */
	struct MessageReference
	{
		Snowflake MessageId;
		Snowflake ChannelId;
		Snowflake GuildId;

		friend std::ostream& operator<<(std::ostream& os, const MessageReference& messageReference);
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

		friend std::ostream& operator<<(std::ostream& os, const MessageSticker& messageSticker);
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

		friend std::ostream& operator<<(std::ostream& os, const Message& message);
	};

	inline std::ostream& operator<<(std::ostream& os, const ChannelMention& channelMention)
	{
		os << "Id: " << channelMention.Id
			<< ", Guild Id: " << channelMention.GuildId
			<< ", Type: " << channelMention.Type
			<< ", Name: " << channelMention.Name;
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const Attachment& attachment)
	{
		os << "Id: " << attachment.Id
			<< ", File Name: " << attachment.Filename
			<< ", Size: " << attachment.Size
			<< ", Url: " << attachment.Url
			<< ", Proxy Url: " << attachment.ProxyUrl
			<< ", Width: " << attachment.Width
			<< ", Height: " << attachment.Heigh;
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const EmbedFooter& embedFooter)
	{
		/*
		os << "Id: " << channelMention.Id
			<< ", Guild Id: " << channelMention.GuildId
			<< ", Type: " << channelMention.Type
			<< ", Name: " << channelMention.Name;
			*/
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const EmbedImage& embedImage)
	{
		/*
		os << "Id: " << channelMention.Id
			<< ", Guild Id: " << channelMention.GuildId
			<< ", Type: " << channelMention.Type
			<< ", Name: " << channelMention.Name;
			*/
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const EmbedThumbnail& embedThumbnail)
	{
		/*
		os << "Id: " << channelMention.Id
			<< ", Guild Id: " << channelMention.GuildId
			<< ", Type: " << channelMention.Type
			<< ", Name: " << channelMention.Name;
			*/
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const EmbedVideo& embedVideo)
	{
		/*
		os << "Id: " << channelMention.Id
			<< ", Guild Id: " << channelMention.GuildId
			<< ", Type: " << channelMention.Type
			<< ", Name: " << channelMention.Name;
			*/
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const EmbedProvider& embedProvider)
	{
		/*
		os << "Id: " << channelMention.Id
			<< ", Guild Id: " << channelMention.GuildId
			<< ", Type: " << channelMention.Type
			<< ", Name: " << channelMention.Name;
			*/
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const EmbedAuthor& embedAuthor)
	{
		/*
		os << "Id: " << channelMention.Id
			<< ", Guild Id: " << channelMention.GuildId
			<< ", Type: " << channelMention.Type
			<< ", Name: " << channelMention.Name;
			*/
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const EmbedField& embedField)
	{
		/*
		os << "Id: " << channelMention.Id
			<< ", Guild Id: " << channelMention.GuildId
			<< ", Type: " << channelMention.Type
			<< ", Name: " << channelMention.Name;
			*/
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const Embed& embed)
	{
		/*
		os << "Id: " << channelMention.Id
			<< ", Guild Id: " << channelMention.GuildId
			<< ", Type: " << channelMention.Type
			<< ", Name: " << channelMention.Name;
			*/
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const Reaction& reaction)
	{
		/*
		os << "Id: " << channelMention.Id
			<< ", Guild Id: " << channelMention.GuildId
			<< ", Type: " << channelMention.Type
			<< ", Name: " << channelMention.Name;
			*/
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const MessageType& messageType)
	{
		switch (messageType)
		{
		case MessageType::DEFAULT:
			os << "Default";
			break;
		case MessageType::RECIPIENT_ADD:
			os << "Recipient Add";
			break;
		case MessageType::RECIPIENT_REMOVE:
			os << "Recipient Remove";
			break;
		case MessageType::CALL:
			os << "Call";
			break;
		case MessageType::CHANNEL_NAME_CHANGE:
			os << "Channel Name Change";
			break;
		case MessageType::CHANNEL_ICON_CHANGE:
			os << "Channel Icon Change";
			break;
		case MessageType::CHANNEL_PINNED_MESSAGE:
			os << "Channel Pinned Message";
			break;
		case MessageType::GUILD_MEMBER_JOIN:
			os << "Guild Direct Message";
			break;
		case MessageType::USER_PREMIUM_GUILD_SUBSCRIPTION:
			os << "User Premium Guild Subscription";
			break;
		case MessageType::USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_1:
			os << "User Premium Guild Subscription Tier 1";
			break;
		case MessageType::USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_2:
			os << "User Premium Guild Subscription Tier 2";
			break;
		case MessageType::USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_3:
			os << "User Premium Guild Subscription Tier 3";
			break;
		case MessageType::CHANNEL_FOLLOW_ADD:
			os << "Channel Follow Add";
			break;
		case MessageType::GUILD_DISCOVERY_DISQUALIFIED:
			os << "Guild Discovery Disqualified";
			break;
		case MessageType::GUILD_DISCOVERY_REQUALIFIED:
			os << "Group Discovery Requalified";
			break;
		case MessageType::REPLY:
			os << "Reply";
			break;
		}
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const MessageActivityType& messageActivityType)
	{
		switch (messageActivityType)
		{
		case MessageActivityType::JOIN:
			os << "Join";
			break;
		case MessageActivityType::SPECTATE:
			os << "Spectate";
			break;
		case MessageActivityType::LISTEN:
			os << "Listen";
			break;
		case MessageActivityType::JOIN_REQUEST:
			os << "Join request";
			break;
		}
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const MessageActivity& messageActivity)
	{
		/*
		os << "Id: " << channelMention.Id
			<< ", Guild Id: " << channelMention.GuildId
			<< ", Type: " << channelMention.Type
			<< ", Name: " << channelMention.Name;
			*/
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const MessageApplication& messageApplication)
	{
		/*
		os << "Id: " << channelMention.Id
			<< ", Guild Id: " << channelMention.GuildId
			<< ", Type: " << channelMention.Type
			<< ", Name: " << channelMention.Name;
			*/
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const MessageReference& messageReference)
	{
		/*
		os << "Id: " << channelMention.Id
			<< ", Guild Id: " << channelMention.GuildId
			<< ", Type: " << channelMention.Type
			<< ", Name: " << channelMention.Name;
			*/
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const MessageStickerType& messageStickerType)
	{
		switch (messageStickerType)
		{
		case MessageStickerType::PNG:
			os << "PNG";
			break;
		case MessageStickerType::APNG:
			os << "APNG";
			break;
		case MessageStickerType::LOTTIE:
			os << "Lottie";
			break;
		}
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const MessageSticker& messageSticker)
	{
		/*
		os << "Id: " << channelMention.Id
			<< ", Guild Id: " << channelMention.GuildId
			<< ", Type: " << channelMention.Type
			<< ", Name: " << channelMention.Name;
			*/
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, const Message& message)
	{
		/*
		os << "Id: " << channelMention.Id
			<< ", Guild Id: " << channelMention.GuildId
			<< ", Type: " << channelMention.Type
			<< ", Name: " << channelMention.Name;
			*/
		return os;
	}
}
