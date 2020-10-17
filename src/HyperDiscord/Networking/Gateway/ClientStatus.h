#pragma once

#include <iostream>
#include <string>

namespace HyperDiscord
{
	/* https://discord.com/developers/docs/topics/gateway#client-status-object */
	class ClientStatus
	{
	private:
		std::string m_Desktop;
		std::string m_Mobile;
		std::string m_Web;

	public:
		ClientStatus(const std::string& desktop, const std::string& mobile, const std::string& web);

		void SetDesktop(const std::string& desktop);
		const std::string& GetDesktop() const;

		void SetMobile(const std::string& mobile);
		const std::string& GetMobile() const;

		void SetWeb(const std::string& web);
		const std::string& GetWeb() const;

		friend std::ostream& operator<<(std::ostream& os, const ClientStatus& clientStatus);
	};

	inline std::ostream& operator<<(std::ostream& os, const ClientStatus& clientStatus)
	{
		os << "Desktop: " << clientStatus.GetDesktop()
			<< "Mobile: " << clientStatus.GetMobile()
			<< "Web: " << clientStatus.GetWeb();
		return os;
	}
}
