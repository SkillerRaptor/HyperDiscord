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
#include "Networking/Gateway/Activity.h"
#include "Objects/Snowflake.h"
#include "Utilities/Timestamp.h"

namespace HyperDiscord
{
	enum class ActivityStatusType
	{
		PLAYING = 1,
		LISTENING,
		WATCHING
	};

	enum class StatusType
	{
		ONLINE = 0,
		DND,
		IDLE,
		INVISIBLE,
		OFFLINE
	};
	
	struct StatusInfo
	{
		uint32_t Since;
		std::string Name;
		ActivityStatusType Type;
		StatusType Status;
		bool Afk;
	};

	class HyperClient
	{
	private:
		Token m_Token;
		NetworkClient* m_NetworkClient;
		Timestamp m_Uptime;

		ChannelManager* m_ChannelManger;
		EmojiManager* m_EmojiManger;
		GuildManager* m_GuildManager;

		std::queue<std::shared_ptr<Event>> m_EventBus;
		std::vector<std::function<void(Event&)>> m_EventFunctions;

	public:
		HyperClient(Token token);
		HyperClient(const std::string& token, TokenType tokenType);
		~HyperClient();

		void OnEvent(const typename std::common_type<std::function<void(Event&)>>::type function);

		ChannelManager& GetChannelManager();
		EmojiManager& GetEmojiManager();
		GuildManager& GetGuildManager();

		void SetStatus(StatusInfo statusInfo);

		const Token& GetToken() const;
		Timestamp GetUptime() const;

		void Update();
	};
}
