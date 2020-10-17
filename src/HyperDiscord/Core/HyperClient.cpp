#include "HyperClient.h"

namespace HyperDiscord
{
	HyperClient::HyperClient(Token token)
		: m_Token(token), m_NetworkClient(m_Token)
	{
	}

	HyperClient::HyperClient(const std::string token, TokenType tokenType)
		: HyperClient(Token(token, tokenType))
	{
	}

	HyperClient::~HyperClient()
	{

	}

	Channel HyperClient::GetChannel(Snowflake channelId)
	{
		return m_NetworkClient.GetChannel(channelId);
	}

	void HyperClient::Run()
	{
	}
}
