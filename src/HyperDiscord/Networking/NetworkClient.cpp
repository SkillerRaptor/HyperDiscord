#include "NetworkClient.h"

#include <iostream>
#include <ctime>

#include "Events/GuildEvents.h"
#include "Events/MessageEvents.h"

namespace HyperDiscord
{
	NetworkClient::NetworkClient(Token token, std::queue<std::shared_ptr<Event>>& eventBus)
		: m_Token(token), m_EventBus(eventBus)
	{
		m_EventTypes["GUILD_CREATE"] = EventType::GuildCreate;
		m_EventTypes["MESSAGE_CREATE"] = EventType::MessageCreate;
		m_EventTypes["MESSAGE_UPDATE"] = EventType::MessageUpdate;
		m_EventTypes["MESSAGE_DELETE"] = EventType::MessageDelete;

		m_HTTPClient = new HTTPClient(m_Token);
		m_WebSocketClient = new WebSocketClient();

		m_HeartBeat = nlohmann::json::parse(m_WebSocketClient->Listen())["d"]["heartbeat_interval"];
		nlohmann::json ready = nlohmann::json::parse(m_WebSocketClient->SendData("{\"op\":2,\"d\":{\"token\":\"" + token.GetToken() + "\",\"intents\":513,\"properties\":{\"$os\":\"windows\",\"$browser\":\"HyperDiscord\",\"$device\":\"HyperDiscord\"},\"presence\":{\"activities\":[{\"name\":\"some Hentais\",\"type\":3}],\"status\":\"dnd\",\"since\":91879201,\"afk\":false},\"intents\":7}}"));

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
				/* TODO: GUILD_CREATE */
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
			Guild guild = GetGuildObject(data, "");
			m_EventBus.push(std::make_shared<GuildCreateEvent>(guild));
			break;
		}
		case EventType::MessageCreate:
		{
			Message message = GetMessageObject(data, "");
			m_EventBus.push(std::make_shared<MessageCreateEvent>(message));
			break;
		}
		case EventType::MessageUpdate:
		{
			Message message = GetMessageObject(data, "");
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

	const std::string NetworkClient::Get(const std::string& path)
	{
		return m_HTTPClient->Get(path);
	}

	const std::string NetworkClient::Get(const std::string& path, const Headers& headers)
	{
		return m_HTTPClient->Get(path, headers);
	}

	const std::string NetworkClient::Post(const std::string& path)
	{
		return m_HTTPClient->Post(path);
	}

	const std::string NetworkClient::Post(const std::string& path, const std::string& body)
	{
		return m_HTTPClient->Post(path, body);
	}

	const std::string NetworkClient::Post(const std::string& path, const Headers& headers, const std::string& body)
	{
		return m_HTTPClient->Post(path, headers, body);
	}

	const std::string NetworkClient::Put(const std::string& path)
	{
		return m_HTTPClient->Put(path);
	}

	const std::string NetworkClient::Put(const std::string& path, const std::string& body)
	{
		return m_HTTPClient->Put(path, body);
	}

	const std::string NetworkClient::Put(const std::string& path, const Headers& headers, const std::string& body)
	{
		return m_HTTPClient->Put(path, headers, body);
	}

	const std::string NetworkClient::Patch(const std::string& path)
	{
		return m_HTTPClient->Patch(path);
	}

	const std::string NetworkClient::Patch(const std::string& path, const std::string& body)
	{
		return m_HTTPClient->Patch(path, body);
	}

	const std::string NetworkClient::Patch(const std::string& path, const Headers& headers, const std::string& body)
	{
		return m_HTTPClient->Patch(path, headers, body);
	}

	const std::string NetworkClient::Delete(const std::string& path)
	{
		return m_HTTPClient->Delete(path);
	}

	const std::string NetworkClient::Delete(const std::string& path, const std::string& body)
	{
		return m_HTTPClient->Delete(path, body);
	}

	const std::string NetworkClient::Delete(const std::string& path, const Headers& headers, const std::string& body)
	{
		return m_HTTPClient->Delete(path, headers, body);
	}

	const std::string NetworkClient::Listen()
	{
		return m_WebSocketClient->Listen();
	}

	const std::string NetworkClient::SendData(const std::string& message)
	{
		return m_WebSocketClient->SendData(message);
	}
}
