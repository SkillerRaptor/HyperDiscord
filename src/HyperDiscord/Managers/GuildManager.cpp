#include "GuildManager.h"

namespace HyperDiscord
{
	GuildManager::GuildManager(NetworkClient& networkClient)
		: m_NetworkClient(networkClient)
	{
	}

	std::optional<Guild> GuildManager::GetGuild(Snowflake guildId)
	{
		for (Guild guild : m_Guilds)
			if (guild.Id == guildId)
				return std::optional<Guild>(guild);
		return std::nullopt;
	}

	const std::vector<Guild>& GuildManager::GetGuilds() const
	{
		return m_Guilds;
	}
}
