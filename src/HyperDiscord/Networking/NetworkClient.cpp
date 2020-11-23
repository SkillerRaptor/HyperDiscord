#include "NetworkClient.h"

#include <iostream>
#include <ctime>

#include "Events/MessageEvents.h"

namespace HyperDiscord
{
	NetworkClient::NetworkClient(Token token, std::vector<std::function<void(Event&)>>& eventFunctions)
		: m_Token(token), m_EventFunctions(eventFunctions)
	{
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
					std::string eventName = jsonMessage["t"];
					nlohmann::json dataArray = jsonMessage["d"];
					if (eventName == "MESSAGE_CREATE" || eventName == "MESSAGE_UPDATE")
					{
						Message message{};
						message.Id = GetSnowflake(dataArray, "id");
						message.ChannelId = GetSnowflake(dataArray, "channel_id");
						message.GuildId = GetSnowflake(dataArray, "guild_id");
						message.Author = GetUser(dataArray, "author");
						message.Member = GetGuildMember(dataArray, "member");
						message.Content = GetString(dataArray, "content");
						// TODO: Timestamp
						// TODO: Edited Timestamp
						message.TTS = GetBoolean(dataArray, "tts");
						message.MentionEveryone = GetBoolean(dataArray, "mention_everyone");
						// TODO: Mentions Array
						// TODO: Mention Roles Array
						// TODO: Mention Channels Array
						// TODO: Attachments Array
						// TODO: Embeds Array
						// TODO: Reaction Array
						// NOTE: Nonce
						message.Pinned = GetBoolean(dataArray, "pinned");
						message.WebhookId = GetSnowflake(dataArray, "webhook_id");
						// TODO: Type
						// TODO: Activity Object
						// TODO: Application Object
						// TODO: Reference Object
						// TODO: Flags
						// TODO: Sticker Array
						// TODO: Referenced Message

						if (eventName == "MESSAGE_CREATE")
						{
							MessageCreateEvent event(message);

							for (auto& function : m_EventFunctions)
								function(event);
						}
						else if (eventName == "MESSAGE_UPDATE")
						{
							MessageUpdateEvent event(message);

							for (auto& function : m_EventFunctions)
								function(event);
						}
					}
					else if (eventName == "MESSAGE_DELETE")
					{
						Snowflake channelId = GetSnowflake(dataArray, "channel_id");
						Snowflake guildId = GetSnowflake(dataArray, "guild_id");
						Snowflake id = GetSnowflake(dataArray, "id");

						MessageDeleteEvent event(channelId, guildId, id);

						for (auto& function : m_EventFunctions)
							function(event);
					}
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

	bool NetworkClient::GetBoolean(const nlohmann::json& dataArray, const std::string& key)
	{
		if (!dataArray.contains(key))
			return false;

		if (!dataArray[key].is_boolean() && dataArray[key].is_null())
			return false;

		return static_cast<bool>(dataArray[key]);
	}

	std::string NetworkClient::GetString(const nlohmann::json& dataArray, const std::string& key)
	{
		if (!dataArray.contains(key))
			return "";

		if (!dataArray[key].is_string() && dataArray[key].is_null())
			return "";

		return static_cast<std::string>(dataArray[key]);
	}

	Snowflake NetworkClient::GetSnowflake(const nlohmann::json& dataArray, const std::string& key)
	{
		if (!dataArray.contains(key))
			return Snowflake({});

		if (!dataArray[key].is_string() && dataArray[key].is_null())
			return Snowflake({});

		return Snowflake(std::stoll((std::string)dataArray[key]));
	}

	User NetworkClient::GetUser(const nlohmann::json& dataArray, const std::string& key)
	{
		if (!dataArray.contains(key))
			return User({});

		if (dataArray[key].is_null())
			return User({});

		nlohmann::json array = dataArray[key];

		User user{};
		user.Id = GetSnowflake(array, "id");
		user.Username = GetString(array, "username");
		user.Discriminator = GetString(array, "discriminator");
		user.Avatar = GetString(array, "avatar");
		user.Bot = GetBoolean(array, "bot");
		user.System = GetBoolean(array, "system");
		user.MfaEnabled = GetBoolean(array, "mfa_enabled");
		user.Locale = GetString(array, "locale");
		user.Verified = GetBoolean(array, "verified");
		user.Email = GetString(array, "email");
		// TODO: Flags
		// TODO: Premium Type
		// TODO: Public Flags

		return user;
	}

	GuildMember NetworkClient::GetGuildMember(const nlohmann::json& dataArray, const std::string& key)
	{
		if (!dataArray.contains(key))
			return GuildMember({});
		if (dataArray[key].is_null())
			return GuildMember({});

		nlohmann::json array = dataArray[key];

		GuildMember guildMember{};
		guildMember.User = GetUser(array, "user");
		guildMember.Nick = GetString(array, "nick");
		// TODO: Roles - Snowflake Array
		// TODO: Joined At
		// TODO: Premium Since
		guildMember.Deaf = GetBoolean(array, "deaf");
		guildMember.Mute = GetBoolean(array, "mute");

		return guildMember;
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
