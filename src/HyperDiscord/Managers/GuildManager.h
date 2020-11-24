#pragma once

#ifndef _WIN32
#error HyperDiscord is only supporting Windows in the moment
#endif

#include <optional>
#include <vector>

#include "Networking/NetworkClient.h"
#include "Objects/Guild.h"
#include "Utilities/NonCopyable.h"
#include "Utilities/NonMoveable.h"

namespace HyperDiscord
{
	class GuildManager : public NonCopyable, NonMoveable
	{
	private:
		NetworkClient& m_NetworkClient;

		std::vector<Guild> m_Guilds;

		friend class HyperClient;
	public:
		GuildManager(NetworkClient& networkClient);

		std::optional<Guild> GetGuild(Snowflake guildId);
		const std::vector<Guild>& GetGuilds() const;
	};
}
