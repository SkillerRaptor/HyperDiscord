#include "ClientStatus.h"

namespace HyperDiscord
{
	ClientStatus::ClientStatus(const std::string& desktop, const std::string& mobile, const std::string& web)
		: m_Desktop(desktop), m_Mobile(mobile), m_Web(web)
	{
	}

	void ClientStatus::SetDesktop(const std::string& desktop)
	{
		m_Desktop = desktop;
	}

	const std::string& ClientStatus::GetDesktop() const
	{
		return m_Desktop;
	}

	void ClientStatus::SetMobile(const std::string& mobile)
	{
		m_Mobile = mobile;
	}

	const std::string& ClientStatus::GetMobile() const
	{
		return m_Mobile;
	}

	void ClientStatus::SetWeb(const std::string& web)
	{
		m_Web = web;
	}

	const std::string& ClientStatus::GetWeb() const
	{
		return m_Web;
	}
}
