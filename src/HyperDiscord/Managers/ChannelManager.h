#pragma once

#ifndef _WIN32
#error HyperDiscord is only supporting Windows in the moment
#endif

#include <string>

#include "Networking/NetworkClient.h"
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

	public:
		ChannelManager(NetworkClient& networkClient);

		Message SendMessage(Snowflake channelId, const std::string& message);
		Message EditMessage(Snowflake channelId, Snowflake messageId, const std::string& message);
		Message GetMessage(Snowflake channelId, Snowflake messageId);
		void DeleteMessage(Snowflake channelId, Snowflake messageId);
	};
}
