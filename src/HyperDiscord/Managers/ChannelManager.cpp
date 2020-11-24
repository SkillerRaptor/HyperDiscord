#include "ChannelManager.h"

namespace HyperDiscord
{
	ChannelManager::ChannelManager(NetworkClient& networkClient)
		: m_NetworkClient(networkClient)
	{
	}

	Message ChannelManager::SendMessage(Snowflake channelId, const std::string& message)
	{
		nlohmann::json data = nlohmann::json::parse(m_NetworkClient.Post("/channels/" + static_cast<std::string>(channelId) + "/messages", "{\"content\":" + message + "}"));
		return m_NetworkClient.GetMessageObject(data, "");
	}

	Message ChannelManager::EditMessage(Snowflake channelId, Snowflake messageId, const std::string& message)
	{
		nlohmann::json data = nlohmann::json::parse(m_NetworkClient.Patch("/channels/" + static_cast<std::string>(channelId) + "/messages/" + static_cast<std::string>(messageId), "{\"content\":" + message + "}"));
		return m_NetworkClient.GetMessageObject(data, "");
	}

	Message ChannelManager::GetMessage(Snowflake channelId, Snowflake messageId)
	{
		nlohmann::json data = nlohmann::json::parse(m_NetworkClient.Get("/channels/" + static_cast<std::string>(channelId) + "/messages/" + static_cast<std::string>(messageId)));
		return m_NetworkClient.GetMessageObject(data, "");
	}

	void ChannelManager::DeleteMessage(Snowflake channelId, Snowflake messageId)
	{
		m_NetworkClient.Delete("/channels/" + static_cast<std::string>(channelId) + "/messages/" + static_cast<std::string>(messageId));
	}
}
