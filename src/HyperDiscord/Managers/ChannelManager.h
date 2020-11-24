#pragma once

#ifndef _WIN32
#error HyperDiscord is only supporting Windows in the moment
#endif

#include <string>
#include <optional>
#include <vector>

#include "Networking/NetworkClient.h"
#include "Objects/Channel.h"
#include "Objects/Snowflake.h"
#include "Objects/Message.h"
#include "Utilities/NonCopyable.h"
#include "Utilities/NonMoveable.h"

#undef SendMessage

namespace HyperDiscord
{
	class ChannelManager : public NonCopyable, NonMoveable
	{
	private:
		NetworkClient& m_NetworkClient;

		std::vector<Channel> m_Channels;

		friend class HyperClient;
	public:
		ChannelManager(NetworkClient& networkClient);

		std::optional<Channel> GetChannel(Snowflake channelId);
		const std::vector<Channel>& GetChannels() const;

		std::optional<Message> SendMessage(Snowflake channelId, const std::string& message);
		std::optional<Message> EditMessage(Snowflake channelId, Snowflake messageId, const std::string& message);
		std::optional<Message> GetMessage(Snowflake channelId, Snowflake messageId);
		void DeleteMessage(Snowflake channelId, Snowflake messageId);
	};
}
