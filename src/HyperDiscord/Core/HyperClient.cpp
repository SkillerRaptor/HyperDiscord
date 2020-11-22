#include "HyperClient.h"

namespace HyperDiscord
{
	HyperClient::HyperClient(Token token)
		: m_Token(token), m_NetworkClient(m_Token)
	{
		m_Uptime = Timestamp::Now();
	}

	HyperClient::HyperClient(const std::string& token, TokenType tokenType)
		: HyperClient(Token(token, tokenType))
	{
	}

	HyperClient::~HyperClient()
	{
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
