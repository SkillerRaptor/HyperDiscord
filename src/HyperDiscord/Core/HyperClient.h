#pragma once

#include <string>
#include <vector>

#include "Token.h"
#include "Networking/NetworkClient.h"
#include "Objects/Channel.h"
#include "Objects/Snowflake.h"

namespace HyperDiscord
{
	class HyperClient
	{
	private:
		Token m_Token;
		NetworkClient m_NetworkClient;

	public:
		HyperClient(Token token);
		HyperClient(const std::string token, TokenType tokenType);
		~HyperClient();

		Channel GetChannel(Snowflake channelId);

		void Run();
	};
}
