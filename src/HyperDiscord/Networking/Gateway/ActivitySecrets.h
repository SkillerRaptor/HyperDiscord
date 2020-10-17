#pragma once

#include <iostream>
#include <string>

namespace HyperDiscord
{
	/* https://discord.com/developers/docs/topics/gateway#activity-object-activity-secrets */
	class ActivitySecrets
	{
	private:
		std::string m_Join;
		std::string m_Spectate;
		std::string m_Match;

	public:
		ActivitySecrets(const std::string& join, const std::string& spectate, const std::string& match);

		void SetJoin(const std::string& join);
		const std::string& GetJoin() const;

		void SetSpectate(const std::string& spectate);
		const std::string& GetSpectate() const;

		void SetMatch(const std::string& match);
		const std::string& GetMatch() const;

		friend std::ostream& operator<<(std::ostream& os, const ActivitySecrets& activitySecrets);
	};

	inline std::ostream& operator<<(std::ostream& os, const ActivitySecrets& activitySecrets)
	{
		os << "Join: " << activitySecrets.GetJoin()
			<< ", Spectate: " << activitySecrets.GetSpectate()
			<< ", Match: " << activitySecrets.GetMatch();
		return os;
	}
}
