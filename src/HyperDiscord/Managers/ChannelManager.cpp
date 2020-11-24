#include "ChannelManager.h"

namespace HyperDiscord
{
	ChannelManager::ChannelManager(NetworkClient& networkClient)
		: m_NetworkClient(networkClient)
	{
	}

	std::optional<Channel> ChannelManager::GetChannel(Snowflake channelId)
	{
		for (Channel channel : m_Channels)
			if (channel.Id == channelId)
				return std::optional<Channel>(channel);
		return std::nullopt;
	}

	const std::vector<Channel>& ChannelManager::GetChannels() const
	{
		return m_Channels;
	}

	std::optional<Message> ChannelManager::SendMessage(Snowflake channelId, const std::string& message)
	{
		nlohmann::json data = nlohmann::json::parse(m_NetworkClient.Post("/channels/" + static_cast<std::string>(channelId) + "/messages", "{\"content\":" + message + "}"));
		// TODO: Error Checking
		return std::optional<Message>(m_NetworkClient.GetMessageObject(data, ""));
	}

	std::optional<Message> ChannelManager::EditMessage(Snowflake channelId, Snowflake messageId, const std::string& message)
	{
		nlohmann::json data = nlohmann::json::parse(m_NetworkClient.Patch("/channels/" + static_cast<std::string>(channelId) + "/messages/" + static_cast<std::string>(messageId), "{\"content\":" + message + "}"));
		// TODO: Error Checking
		return std::optional<Message>(m_NetworkClient.GetMessageObject(data, ""));
	}

	std::optional<Message> ChannelManager::GetMessage(Snowflake channelId, Snowflake messageId)
	{
		nlohmann::json data = nlohmann::json::parse(m_NetworkClient.Get("/channels/" + static_cast<std::string>(channelId) + "/messages/" + static_cast<std::string>(messageId)));
		// TODO: Error Checking
		return std::optional<Message>(m_NetworkClient.GetMessageObject(data, ""));
	}

	void ChannelManager::DeleteMessage(Snowflake channelId, Snowflake messageId)
	{
		m_NetworkClient.Delete("/channels/" + static_cast<std::string>(channelId) + "/messages/" + static_cast<std::string>(messageId));
	}
}
