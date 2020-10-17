#include "VoiceRegion.h"

namespace HyperDiscord
{
	VoiceRegion::VoiceRegion(const std::string id, const std::string name, bool vip, bool optimal, bool deprecated, bool custom)
		: m_Id(id), m_Name(name), m_Vip(vip), m_Optimal(optimal), m_Deprecated(deprecated), m_Custom(custom)
	{
	}

	void VoiceRegion::SetId(const std::string& id)
	{
		m_Id = id;
	}

	const std::string& VoiceRegion::GetId() const
	{
		return m_Id;
	}

	void VoiceRegion::SetName(const std::string& name)
	{
		m_Name = name;
	}

	const std::string& VoiceRegion::GetName() const
	{
		return m_Name;
	}

	void VoiceRegion::SetVip(bool vip)
	{
		m_Vip = vip;
	}

	bool VoiceRegion::IsVip() const
	{
		return m_Vip;
	}

	void VoiceRegion::SetOptimal(bool optimal)
	{
		m_Optimal = optimal;
	}

	bool VoiceRegion::IsOptimal() const
	{
		return m_Optimal;
	}

	void VoiceRegion::SetDeprecated(bool deprecated)
	{
		m_Deprecated = deprecated;
	}

	bool VoiceRegion::IsDeprecated() const
	{
		return m_Deprecated;
	}

	void VoiceRegion::SetCustom(bool custom)
	{
		m_Custom = custom;
	}

	bool VoiceRegion::IsCustom() const
	{
		return m_Custom;
	}
}
