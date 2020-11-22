#pragma once

#ifndef _WIN32
#error HyperDiscord is only supporting Windows in the moment
#endif

#include <string>
#include <vector>

#include "Token.h"
#include "Networking/NetworkClient.h"
#include "Objects/Channel.h"
#include "Objects/Snowflake.h"
#include "Utilities/Timestamp.h"

namespace HyperDiscord
{
	class HyperClient
	{
	private:
		Token m_Token;
		NetworkClient m_NetworkClient;
		Timestamp m_Uptime;

	public:
		HyperClient(Token token);
		HyperClient(const std::string& token, TokenType tokenType);
		~HyperClient();


		const Token& GetToken() const;
		Timestamp GetUptime() const;

		void Update();
	};
}
