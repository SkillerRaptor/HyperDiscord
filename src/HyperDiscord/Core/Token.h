#pragma once

#ifndef _WIN32
#error HyperDiscord is only supporting Windows in the moment
#endif

#include <string>

namespace HyperDiscord
{
	enum class TokenType
	{
		NONE = 0,
		BOT,
		OAUTH2_BEARER
	};

	class Token
	{
	private:
		std::string m_Token;
		TokenType m_Type;

	public:
		Token(const std::string& token, TokenType type);

		const std::string GetAuthorization() const;

		const std::string& GetToken() const;
		TokenType GetType() const;
	};
}
