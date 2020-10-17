#pragma once

#include <iostream>
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
		VoiceRegion(const std::string id, const std::string name, bool vip, bool optimal, bool deprecated, bool custom);

		void SetId(const std::string& id);
		const std::string& GetId() const;

		void SetName(const std::string& name);
		const std::string& GetName() const;

		void SetVip(bool vip);
		bool IsVip() const;

		void SetOptimal(bool optimal);
		bool IsOptimal() const;

		void SetDeprecated(bool deprecated);
		bool IsDeprecated() const;

		void SetCustom(bool custom);
		bool IsCustom() const;

		friend std::ostream& operator<<(std::ostream& os, const VoiceRegion& voiceRegion);
	};

	inline std::ostream& operator<<(std::ostream& os, const VoiceRegion& voiceRegion)
	{
		os << "Id: " << voiceRegion.GetId()
			<< ", Name: " << voiceRegion.GetName()
			<< ", Vip: " << voiceRegion.IsVip()
			<< ", Optimal: " << voiceRegion.IsOptimal()
			<< ", Deprecated: " << voiceRegion.IsDeprecated()
			<< ", Custom: " << voiceRegion.IsCustom();
		return os;
	}
}
