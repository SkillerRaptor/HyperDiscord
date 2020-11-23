#include "NetworkClient.h"

#include <json.hpp>

#include <iostream>
#include <ctime>

#include "Events/MessageEvents.h"
#include "Objects/Snowflake.h"

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
					std::cout << eventName << std::endl;
					nlohmann::json dataArray = jsonMessage["d"];
					if (eventName == "MESSAGE_CREATE")
					{
						Message message{};
						message.Id = Snowflake(std::stoll((std::string)dataArray["id"]));
						message.ChannelId = Snowflake(std::stoll((std::string)dataArray["channel_id"]));
						message.Content = (std::string)dataArray["content"];

						MessageCreateEvent event(message);

						for (auto& function : m_EventFunctions)
							function(event);
					}
					else if (eventName == "MESSAGE_DELETE")
					{
						Snowflake channelId = Snowflake(std::stoll((std::string)dataArray["channel_id"]));
						Snowflake id = Snowflake(std::stoll((std::string)dataArray["id"]));

						Snowflake guildId;
						if(!dataArray["guild_id"].is_null()) guildId = Snowflake(std::stoll((std::string)dataArray["guild_id"]));

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
		unsigned int currentTime = clock();
		while (m_Running)
		{
			time_t check = (clock() - currentTime) / CLOCKS_PER_SEC * 1000;

			while (check >= m_HeartBeat)
			{
				m_WebSocketClient->SendData("{\"op\":1,\"d\":" + std::to_string(m_LastSequenceNumber) + "}");
				std::cout << "[HyperDiscord] HeartBeating" << std::endl;

				currentTime = clock();
				check = 0;
			}
		}
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
