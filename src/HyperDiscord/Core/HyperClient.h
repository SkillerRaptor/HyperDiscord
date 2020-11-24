#pragma once

#ifndef _WIN32
#error HyperDiscord is only supporting Windows in the moment
#endif

#include <functional>
#include <memory>
#include <string>
#include <queue>
#include <vector>

#include "Token.h"
#include "Events/Event.h"
#include "Managers/ChannelManager.h"
#include "Managers/EmojiManager.h"
#include "Managers/GuildManager.h"
#include "Networking/NetworkClient.h"
#include "Objects/Snowflake.h"
#include "Utilities/Timestamp.h"

namespace HyperDiscord
{
	class HyperClient
	{
	private:
		Token m_Token;
		NetworkClient* m_NetworkClient;
		Timestamp m_Uptime;

		ChannelManager m_ChannelManger;
		EmojiManager m_EmojiManger;
		GuildManager m_GuildManager;

		std::queue<std::shared_ptr<Event>> m_EventBus;
		std::vector<std::function<void(Event&)>> m_EventFunctions;

	public:
		HyperClient(Token token);
		HyperClient(const std::string& token, TokenType tokenType);
		~HyperClient();

		void OnEvent(const typename std::common_type<std::function<void(Event&)>>::type function);

		const ChannelManager& GetChannelManager() const;
		const EmojiManager& GetEmojiManager() const;
		const GuildManager& GetGuildManager() const;

		const Token& GetToken() const;
		Timestamp GetUptime() const;

		void Update();
	};
}
