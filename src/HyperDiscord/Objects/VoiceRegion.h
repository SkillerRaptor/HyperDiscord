#pragma once

#include <iostream>
#include <string>

namespace HyperDiscord
{
	/* https://discord.com/developers/docs/resources/voice#voice-region-object-voice-region-structure */
	struct VoiceRegion
	{
		std::string Id;
		std::string Name;
		bool Vip;
		bool Optimal;
		bool Deprecated;
		bool Custom;

		friend std::ostream& operator<<(std::ostream& os, const VoiceRegion& voiceRegion);
	};

	inline std::ostream& operator<<(std::ostream& os, const VoiceRegion& voiceRegion)
	{
		os << "Id: " << voiceRegion.Id
			<< ", Name: " << voiceRegion.Name
			<< ", Vip: " << voiceRegion.Vip
			<< ", Optimal: " << voiceRegion.Optimal
			<< ", Deprecated: " << voiceRegion.Deprecated
			<< ", Custom: " << voiceRegion.Custom;
		return os;
	}
}
