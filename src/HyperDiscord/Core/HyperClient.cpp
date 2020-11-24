#include "HyperClient.h"

#include <iostream>

#include "Events/GuildEvents.h"
#include "Events/MessageEvents.h"

namespace HyperDiscord
{
	HyperClient::HyperClient(Token token)
		: m_Token(token), m_Uptime(Timestamp::Now())
	{
		m_NetworkClient = new NetworkClient(m_Token, m_EventBus);
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

				dispatcher.Dispatch<MessageCreateEvent>([&](MessageCreateEvent& messageCreateEvent)
					{
					});

				dispatcher.Dispatch<MessageUpdateEvent>([&](MessageUpdateEvent& messageUpdateEvent)
					{
					});

				dispatcher.Dispatch<MessageDeleteEvent>([&](MessageDeleteEvent& messageDeleteEvent)
					{
					});
			});
	}

	HyperClient::HyperClient(const std::string& token, TokenType tokenType)
		: HyperClient(Token(token, tokenType))
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

	const ChannelManager& HyperClient::GetChannelManager() const
	{
		return *m_ChannelManger;
	}

	const EmojiManager& HyperClient::GetEmojiManager() const
	{
		return *m_EmojiManger;
	}

	const GuildManager& HyperClient::GetGuildManager() const
	{
		return *m_GuildManager;
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
