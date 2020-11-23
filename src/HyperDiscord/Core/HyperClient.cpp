#include "HyperClient.h"

#include <iostream>

#include "Events/MessageEvents.h"

namespace HyperDiscord
{
	HyperClient::HyperClient(Token token)
		: m_Token(token), m_Uptime(Timestamp::Now())
	{
		m_NetworkClient = new NetworkClient(m_Token, m_EventFunctions);
		std::cout << "[HyperDiscord] Started Bot" << std::endl;
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

	const ChannelManager& HyperClient::GetChannels() const
	{
		return ChannelManager();
	}

	const EmojiManager& HyperClient::GetEmojis() const
	{
		return EmojiManager();
	}

	const GuildManager& HyperClient::GetGuilds() const
	{
		return GuildManager();
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
	}
}
