#include "HyperClient.h"

#include <iostream>

#include "Events/GeneralEvents.h"
#include "Events/GuildEvents.h"
#include "Events/MessageEvents.h"

namespace HyperDiscord
{
	HyperClient::HyperClient(Token token, Intent intents)
		: m_Token(token), m_Intents(intents), m_Uptime(Timestamp::Now())
	{
		m_NetworkClient = new NetworkClient(m_Token, m_Intents, m_EventBus);
		m_ChannelManger = new ChannelManager(*m_NetworkClient);
		m_EmojiManger = new EmojiManager();
		m_GuildManager = new GuildManager(*m_NetworkClient);

		OnEvent([&](Event& event)
			{
				EventDispatcher dispatcher(event);
				dispatcher.Dispatch<GuildCreateEvent>([&](GuildCreateEvent& guildCreateEvent)
					{
						m_GuildManager->m_Guilds.push_back(guildCreateEvent.GetGuild());

						for (Channel channel : guildCreateEvent.GetGuild().Channels)
							m_ChannelManger->m_Channels.push_back(channel);
					});
			});
	}

	HyperClient::HyperClient(const std::string& token, TokenType tokenType, Intent intents)
		: HyperClient(Token(token, tokenType), intents)
	{
	}

	HyperClient::~HyperClient()
	{
		delete m_NetworkClient;
	}

	void HyperClient::OnEvent(const typename std::common_type<std::function<void(Event&)>>::type function)
	{
		m_EventFunctions.push_back(function);
	}

	ChannelManager& HyperClient::GetChannelManager()
	{
		return *m_ChannelManger;
	}

	EmojiManager& HyperClient::GetEmojiManager()
	{
		return *m_EmojiManger;
	}

	GuildManager& HyperClient::GetGuildManager()
	{
		return *m_GuildManager;
	}

	void HyperClient::SetStatus(StatusInfo statusInfo)
	{
		std::string statusName;
		switch (statusInfo.Status)
		{
		case StatusType::ONLINE:
			statusName = "online";
			break;
		case StatusType::DND:
			statusName = "dnd";
			break;
		case StatusType::IDLE:
			statusName = "idle";
			break;
		case StatusType::INVISIBLE:
			statusName = "invisible";
			break;
		case StatusType::OFFLINE:
			statusName = "offline";
			break;
		}

		m_NetworkClient->SendData("{\"op\":3,\"d\":{\"since\":" + std::to_string(statusInfo.Since) + ",\"activities\":[{\"name\":\"" + statusInfo.Name + "\",\"type\":" + std::to_string(static_cast<int>(statusInfo.Type)) + "}],\"status\":\"" + statusName + "\",\"afk\":" + (statusInfo.Afk ? "true" : "false") + "}}");
	}

	const Token& HyperClient::GetToken() const
	{
		return m_Token;
	}

	Timestamp HyperClient::GetUptime() const
	{
		return Timestamp::Now() - m_Uptime;
	}

	void HyperClient::Update()
	{
		while (m_EventBus.size() > 0)
		{
			std::shared_ptr<Event> e = m_EventBus.front();
			for (const auto& function : m_EventFunctions)
				function(*e);
			m_EventBus.pop();
		}
	}
}
