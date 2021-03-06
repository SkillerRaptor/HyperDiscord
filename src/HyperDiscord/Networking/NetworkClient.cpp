#include "NetworkClient.h"

#include <iostream>
#include <ctime>

#include "Events/ChannelEvents.h"
#include "Events/GeneralEvents.h"
#include "Events/GuildEvents.h"
#include "Events/MessageEvents.h"

namespace HyperDiscord
{
	NetworkClient::NetworkClient(Token token, Intent intents, std::queue<std::shared_ptr<Event>>& eventBus)
		: m_Token(token), m_Intents(intents), m_EventBus(eventBus)
	{
		m_EventTypes["CHANNEL_CREATE"] = EventType::ChannelCreate;
		m_EventTypes["CHANNEL_UPDATE"] = EventType::ChannelUpdate;
		m_EventTypes["CHANNEL_DELETE"] = EventType::ChannelDelete;
		m_EventTypes["CHANNEL_PINS_UPDATE"] = EventType::ChannelPinsUpdate;
		m_EventTypes["GUILD_CREATE"] = EventType::GuildCreate;
		m_EventTypes["GUILD_UPDATE"] = EventType::GuildUpdate;
		m_EventTypes["GUILD_DELETE"] = EventType::GuildDelete;
		m_EventTypes["GUILD_BAN_ADD"] = EventType::GuildBanAdd;
		m_EventTypes["GUILD_BAN_REMOVE"] = EventType::GuildBanRemove;
		m_EventTypes["GUILD_EMOJIS_UPDATE"] = EventType::GuildEmojisUpdate;
		m_EventTypes["GUILD_INTEGRATIONS_UPDATE"] = EventType::GuildIntegrationsUpdate;
		m_EventTypes["GUILD_MEMBER_ADD"] = EventType::GuildMemberAdd;
		m_EventTypes["GUILD_MEMBER_UPDATE"] = EventType::GuildMemberUpdate;
		m_EventTypes["GUILD_MEMBER_REMOVE"] = EventType::GuildMemberRemove;
		m_EventTypes["GUILD_MEMBER_CHUNK"] = EventType::GuildMemberChunk;
		m_EventTypes["GUILD_ROLE_CREATE"] = EventType::GuildRoleCreate;
		m_EventTypes["GUILD_ROLE_UPDATE"] = EventType::GuildRoleUpdate;
		m_EventTypes["GUILD_ROLE_DELETE"] = EventType::GuildRoleDelete;
		m_EventTypes["INVITE_CREATE"] = EventType::InviteCreate;
		m_EventTypes["INVITE_DELETE"] = EventType::InviteDelete;
		m_EventTypes["MESSAGE_CREATE"] = EventType::MessageCreate;
		m_EventTypes["MESSAGE_UPDATE"] = EventType::MessageUpdate;
		m_EventTypes["MESSAGE_DELETE"] = EventType::MessageDelete;
		m_EventTypes["MESSAGE_DELETE_BULK"] = EventType::MessageDeleteBulk;
		m_EventTypes["MESSAGE_REACTION_ADD"] = EventType::MessageReactionAdd;
		m_EventTypes["MESSAGE_REACTION_REMOVE"] = EventType::MessageReactionRemove;
		m_EventTypes["MESSAGE_REACTION_REMOVE_ALL"] = EventType::MessageReactionRemoveAll;
		m_EventTypes["MESSAGE_REACTION_REMOVE_EMOJI"] = EventType::MessageReactionRemoveEmoji;
		m_EventTypes["PRESENCE_UPDATE"] = EventType::PresenceUpdate;
		m_EventTypes["TYPING_START"] = EventType::TypingStart;
		m_EventTypes["USER_UPDATE"] = EventType::UserUpdate;
		m_EventTypes["VOICE_STATE_UPDATE"] = EventType::VoiceStateUpdate;
		m_EventTypes["VOICE_SERVER_UPDATE"] = EventType::VoiceServerUpdate;
		m_EventTypes["WEBHOOKS_UPDATE"] = EventType::WebhooksUpdate;

		m_HTTPClient = new HTTPClient(m_Token);
		m_WebSocketClient = new WebSocketClient();

		m_HeartBeat = nlohmann::json::parse(m_WebSocketClient->Listen())["d"]["heartbeat_interval"];
		nlohmann::json ready = nlohmann::json::parse(m_WebSocketClient->SendData("{\"op\":2,\"d\":{\"token\":\"" + token.GetToken() + "\",\"intents\":" + std::to_string((intents & Intent::NOTHING) ? 513 : intents) + ",\"properties\":{\"$os\":\"windows\",\"$browser\":\"HyperDiscord\",\"$device\":\"HyperDiscord\"}}}"));

		m_HeartBeatingThread = std::thread(&NetworkClient::HeartBeating, this);
		m_ListeningThread = std::thread(&NetworkClient::Listening, this);
	}

	NetworkClient::~NetworkClient()
	{
		m_Running = false;

		delete m_HTTPClient;
		delete m_WebSocketClient;
	}

	void NetworkClient::Listening()
	{
		while (m_Running)
		{
			std::string message = m_WebSocketClient->Listen();
			if (!message.empty() && message != "")
			{
				nlohmann::json jsonMessage = nlohmann::json::parse(message);
				if (jsonMessage["s"].is_null() && jsonMessage["s"].is_number())
					m_LastSequenceNumber = jsonMessage["s"];

				/* Handle Events */
				if (!jsonMessage["t"].is_null() && jsonMessage["t"].is_string())
				{
					std::string eventName = GetStringObject(jsonMessage, "t");
					if (m_EventTypes.find(eventName) != m_EventTypes.end())
						OnEvent(m_EventTypes.at(eventName), jsonMessage["d"]);
				}
			}
		}
	}

	void NetworkClient::HeartBeating()
	{
		clock_t currentTime = clock();
		while (m_Running)
		{
			time_t check = (clock() - currentTime) / CLOCKS_PER_SEC * (clock_t)1000UL;

			while (check >= m_HeartBeat)
			{
				m_WebSocketClient->SendData("{\"op\":1,\"d\":" + std::to_string(m_LastSequenceNumber) + "}");

				currentTime = clock();
				check = 0;
			}
		}
	}

	void NetworkClient::OnEvent(EventType eventType, const nlohmann::json& data)
	{
		switch (eventType)
		{
		case EventType::GuildCreate:
		{
			Guild guild = GetGuildObject(data);
			m_EventBus.push(std::make_shared<GuildCreateEvent>(guild));
			break;
		}
		case EventType::MessageCreate:
		{
			Message message = GetMessageObject(data);
			m_EventBus.push(std::make_shared<MessageCreateEvent>(message));
			break;
		}
		case EventType::MessageUpdate:
		{
			Message message = GetMessageObject(data);
			m_EventBus.push(std::make_shared<MessageUpdateEvent>(message));
			break;
		}
		case EventType::MessageDelete:
		{
			Snowflake channelId = GetSnowflakeObject(data, "channel_id");
			Snowflake guildId = GetSnowflakeObject(data, "guild_id");
			Snowflake id = GetSnowflakeObject(data, "id");
			m_EventBus.push(std::make_shared<MessageDeleteEvent>(channelId, guildId, id));
			break;
		}
		case EventType::Ready:
		{
			uint8_t version = GetIntegerObject(data, "v");
			User user = GetUserObject(data, "user");
			std::vector<Guild> guilds;
			nlohmann::json guildArray = GetArrayObject(data, "guilds");
			for (nlohmann::json guildObject : guildArray)
				guilds.push_back(GetGuildObject(guildObject));
			std::string sessionId = GetStringObject(data, "session_id");
			m_EventBus.push(std::make_shared<ReadyEvent>(version, user, guilds, sessionId));
			break;
		}
		}
	}

	bool NetworkClient::GetBooleanObject(const nlohmann::json& dataArray, const std::string& key)
	{
		if (!dataArray.contains(key))
			return false;

		if (!dataArray[key].is_boolean() && dataArray[key].is_null())
			return false;

		return static_cast<bool>(dataArray[key]);
	}


	int NetworkClient::GetIntegerObject(const nlohmann::json& dataArray, const std::string& key)
	{
		if (!dataArray.contains(key))
			return -1;

		if (!dataArray[key].is_string() && dataArray[key].is_null())
			return -1;

		return static_cast<int>(dataArray[key]);
	}

	std::string NetworkClient::GetStringObject(const nlohmann::json& dataArray, const std::string& key)
	{
		if (!dataArray.contains(key))
			return "";

		if (!dataArray[key].is_string() && dataArray[key].is_null())
			return "";

		return static_cast<std::string>(dataArray[key]);
	}


	nlohmann::json NetworkClient::GetArrayObject(const nlohmann::json& dataArray, const std::string& key)
	{
		if (!dataArray.contains(key))
			return nlohmann::json();

		if (dataArray[key].is_null())
			return nlohmann::json();

		return static_cast<nlohmann::json>(dataArray[key]);
	}

	Snowflake NetworkClient::GetSnowflakeObject(const nlohmann::json& dataArray, const std::string& key)
	{
		if (!dataArray.contains(key))
			return Snowflake({});

		if (!dataArray[key].is_string() && dataArray[key].is_null())
			return Snowflake({});

		return Snowflake(std::stoll(GetStringObject(dataArray, key)));
	}

	Iso8601 NetworkClient::GetIso8061Object(const nlohmann::json& dataArray, const std::string& key)
	{
		if (!dataArray.contains(key))
			return Iso8601({});

		if (!dataArray[key].is_string() && dataArray[key].is_null())
			return Iso8601({});

		return Iso8601(GetStringObject(dataArray, key));
	}


	Channel NetworkClient::GetChannelObject(const nlohmann::json& dataArray, const std::string& key)
	{
		nlohmann::json data = dataArray;
		if (!key.empty() || key != "")
		{
			if (!dataArray.contains(key))
				return Channel({});
			if (dataArray[key].is_null())
				return Channel({});

			data = dataArray[key];
		}

		Channel channel{};
		channel.Id = GetSnowflakeObject(data, "id");
		channel.Type = static_cast<ChannelType>(GetIntegerObject(data, "type"));
		channel.GuildId = GetSnowflakeObject(data, "guild_id");
		channel.Position = GetIntegerObject(data, "position");
		// TODO: Permission Overwrites
		channel.Name = GetStringObject(data, "name");
		channel.Topic = GetStringObject(data, "topic");
		channel.Nsfw = GetBooleanObject(data, "nsfw");
		channel.LastMessageId = GetSnowflakeObject(data, "last_message_id");
		channel.Bitrate = GetIntegerObject(data, "bitrate");
		channel.UserLimit = GetIntegerObject(data, "user_limit");
		channel.RateLimitPerUser = GetIntegerObject(data, "rate_limit_per_user");
		// TODO: Recipients
		channel.Icon = GetStringObject(data, "icon");
		channel.OwnerId = GetSnowflakeObject(data, "owner_id");
		channel.ApplicationId = GetSnowflakeObject(data, "application_id");
		channel.ParentId = GetSnowflakeObject(data, "parent_id");
		channel.LastPinTimestamp = GetIso8061Object(data, "last_pin_timestamp");

		return channel;
	}

	Guild NetworkClient::GetGuildObject(const nlohmann::json& dataArray, const std::string& key)
	{
		nlohmann::json data = dataArray;
		if (!key.empty() || key != "")
		{
			if (!dataArray.contains(key))
				return Guild({});
			if (dataArray[key].is_null())
				return Guild({});

			data = dataArray[key];
		}


		Guild guild{};
		guild.Id = GetSnowflakeObject(data, "id");

		for (auto& channel : GetArrayObject(data, "channels"))
			guild.Channels.push_back(GetChannelObject(channel, ""));

		for (auto& member : GetArrayObject(data, "members"))
			guild.Members.push_back(GetGuildMemberObject(member, ""));

		// TODO: Doing rest...

		return guild;
	}

	User NetworkClient::GetUserObject(const nlohmann::json& dataArray, const std::string& key)
	{
		nlohmann::json data = dataArray;
		if (!key.empty() || key != "")
		{
			if (!dataArray.contains(key))
				return User({});
			if (dataArray[key].is_null())
				return User({});

			data = dataArray[key];
		}

		User user{};
		user.Id = GetSnowflakeObject(data, "id");
		user.Username = GetStringObject(data, "username");
		user.Discriminator = GetStringObject(data, "discriminator");
		user.Avatar = GetStringObject(data, "avatar");
		user.Bot = GetBooleanObject(data, "bot");
		user.System = GetBooleanObject(data, "system");
		user.MfaEnabled = GetBooleanObject(data, "mfa_enabled");
		user.Locale = GetStringObject(data, "locale");
		user.Verified = GetBooleanObject(data, "verified");
		user.Email = GetStringObject(data, "email");
		// TODO: Flags
		// TODO: Premium Type
		// TODO: Public Flags

		return user;
	}

	GuildMember NetworkClient::GetGuildMemberObject(const nlohmann::json& dataArray, const std::string& key)
	{
		nlohmann::json data = dataArray;
		if (!key.empty() || key != "")
		{
			if (!dataArray.contains(key))
				return GuildMember({});
			if (dataArray[key].is_null())
				return GuildMember({});

			data = dataArray[key];
		}

		GuildMember guildMember{};
		guildMember.User = GetUserObject(data, "user");
		guildMember.Nick = GetStringObject(data, "nick");
		// TODO: Roles - Snowflake Array
		guildMember.JoinedAt = GetIso8061Object(data, "joined_at");
		guildMember.PremiumSince = GetIso8061Object(data, "premium_since");
		guildMember.Deaf = GetBooleanObject(data, "deaf");
		guildMember.Mute = GetBooleanObject(data, "mute");

		return guildMember;
	}

	Message NetworkClient::GetMessageObject(const nlohmann::json& dataArray, const std::string& key)
	{
		nlohmann::json data = dataArray;
		if (!key.empty() || key != "")
		{
			if (!dataArray.contains(key))
				return Message({});
			if (dataArray[key].is_null())
				return Message({});

			data = dataArray[key];
		}

		Message message{};
		message.Id = GetSnowflakeObject(data, "id");
		message.ChannelId = GetSnowflakeObject(data, "channel_id");
		message.GuildId = GetSnowflakeObject(data, "guild_id");
		message.Author = GetUserObject(data, "author");
		message.Member = GetGuildMemberObject(data, "member");
		message.Content = GetStringObject(data, "content");
		message.Timestamp = GetIso8061Object(data, "timestamp");
		message.EditedTimestamp = GetIso8061Object(data, "edited_timestamp");
		message.TTS = GetBooleanObject(data, "tts");
		message.MentionEveryone = GetBooleanObject(data, "mention_everyone");
		// TODO: Mentions Array
		// TODO: Mention Roles Array
		// TODO: Mention Channels Array
		// TODO: Attachments Array
		// TODO: Embeds Array
		// TODO: Reaction Array
		// NOTE: Nonce
		message.Pinned = GetBooleanObject(data, "pinned");
		message.WebhookId = GetSnowflakeObject(data, "webhook_id");
		// TODO: Type
		// TODO: Activity Object
		// TODO: Application Object
		// TODO: Reference Object
		// TODO: Flags
		// TODO: Sticker Array
		// TODO: Referenced Message

		return message;
	}

	const std::optional<nlohmann::json> NetworkClient::Get(const std::string& path)
	{
		std::string response = m_HTTPClient->Get(path);
		nlohmann::json data = nlohmann::json::parse(response);
		if (data.contains("code") && data.contains("message"))
		{
			std::cerr << "[HyperDiscord] Error Code '" << data["code"] << "' with message " << data["message"] << std::endl;
			return std::nullopt;
		}
		return data;
	}

	const std::optional<nlohmann::json> NetworkClient::Post(const std::string& path, const std::string& body)
	{
		std::string response = m_HTTPClient->Post(path, body);
		nlohmann::json data = nlohmann::json::parse(response);
		if (data.contains("code") && data.contains("message"))
		{
			std::cerr << "[HyperDiscord] Error Code '" << data["code"] << "' with message " << data["message"] << std::endl;
			return std::nullopt;
		}
		return data;
	}

	const std::optional<nlohmann::json> NetworkClient::Put(const std::string& path, const std::string& body)
	{
		std::string response = m_HTTPClient->Put(path, body);
		if (response.empty() || response == "")
			return nlohmann::json::parse("{}");
		nlohmann::json data = nlohmann::json::parse(response);
		if (data.contains("code") && data.contains("message"))
		{
			std::cerr << "[HyperDiscord] Error Code '" << data["code"] << "' with message " << data["message"] << std::endl;
			return std::nullopt;
		}
		return data;
	}

	const std::optional<nlohmann::json> NetworkClient::Patch(const std::string& path, const std::string& body)
	{
		std::string response = m_HTTPClient->Patch(path, body);
		nlohmann::json data = nlohmann::json::parse(response);
		if (data.contains("code") && data.contains("message"))
		{
			std::cerr << "[HyperDiscord] Error Code '" << data["code"] << "' with message " << data["message"] << std::endl;
			return std::nullopt;
		}
		return data;
	}

	void NetworkClient::Delete(const std::string& path)
	{
		std::string response = m_HTTPClient->Delete(path);
		if (response.empty() || response == "")
			return;
		nlohmann::json data = nlohmann::json::parse(response);
		std::cerr << "[HyperDiscord] Error Code '" << data["code"] << "' with message " << data["message"] << std::endl;
	}

	const std::string NetworkClient::SendData(const std::string& message)
	{
		return m_WebSocketClient->SendData(message);
	}
}
