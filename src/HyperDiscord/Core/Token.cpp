#include "Token.h"

#include <iostream>

namespace HyperDiscord
{
	Token::Token(const std::string& token, TokenType type)
		: m_Token(token), m_Type(type)
	{
		if (m_Token == "" || m_Token.empty() || m_Token.size() <= 0)
		{
			std::cerr << "[HyperDiscord] The Token is not allowed to be empty!" << std::endl;
			exit(-1);
		}
	}

	const std::string Token::GetAuthorization() const
	{
		switch (m_Type)
		{
		case TokenType::BOT:
			return "Bot " + m_Token;

		case TokenType::OAUTH2_BEARER:
			return "Bearer " + m_Token;

		default:
			return m_Token;
		}
	}

	const std::string& Token::GetToken() const
	{
		return m_Token;
	}

	TokenType Token::GetType() const
	{
		return TokenType();
	}
}
