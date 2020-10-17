#include "ActivityEmoji.h"
#include "ActivitySecrets.h"

namespace HyperDiscord
{
	ActivitySecrets::ActivitySecrets(const std::string& join, const std::string& spectate, const std::string& match)
		: m_Join(join), m_Spectate(spectate), m_Match(match)
	{
	}

	void ActivitySecrets::SetJoin(const std::string& join)
	{
		m_Join = join;
	}

	const std::string& ActivitySecrets::GetJoin() const
	{
		return m_Join;
	}

	void ActivitySecrets::SetSpectate(const std::string& spectate)
	{
		m_Spectate = spectate;
	}

	const std::string& ActivitySecrets::GetSpectate() const
	{
		return m_Spectate;
	}

	void ActivitySecrets::SetMatch(const std::string& match)
	{
		m_Match = match;
	}

	const std::string& ActivitySecrets::GetMatch() const
	{
		return m_Match;
	}
}
