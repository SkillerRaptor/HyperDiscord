#pragma once

#include <string>

#include "Token.h"

namespace HyperDiscord
{
	class HyperClient
	{
	private:
		Token m_Token;

	public:
		HyperClient(Token token);
		HyperClient(const std::string token, TokenType tokenType);
		~HyperClient();

		void Run();
	};
}
