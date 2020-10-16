#include "HyperClient.h"

namespace HyperDiscord
{
	HyperClient::HyperClient(Token token)
		: m_Token(token)
	{
	}

	HyperClient::HyperClient(const std::string token, TokenType tokenType)
		: HyperClient(Token(token, tokenType))
	{
	}

	HyperClient::~HyperClient()
	{

	}

	void HyperClient::Run()
	{
	}
}
