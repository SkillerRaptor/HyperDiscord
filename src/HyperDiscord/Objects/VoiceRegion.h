#pragma once

#include <string>

namespace HyperDiscord
{
	/* https://discord.com/developers/docs/resources/voice#voice-region-object-voice-region-structure */
	class VoiceRegion
	{
	private:
		std::string m_Id;
		std::string m_Name;
		bool m_Vip;
		bool m_Optimal;
		bool m_Deprecated;
		bool m_Custom;

	public:
		VoiceRegion();
		~VoiceRegion();
	};
}
