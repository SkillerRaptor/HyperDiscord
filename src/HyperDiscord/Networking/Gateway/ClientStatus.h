#pragma once

#ifndef _WIN32
#error HyperDiscord is only supporting Windows in the moment
#endif

#include <iostream>
#include <string>

namespace HyperDiscord
{
	/* https://discord.com/developers/docs/topics/gateway#client-status-object */
	struct ClientStatus
	{
		std::string Desktop;
		std::string Mobile;
		std::string Web;

		friend std::ostream& operator<<(std::ostream& os, const ClientStatus& clientStatus);
	};

	inline std::ostream& operator<<(std::ostream& os, const ClientStatus& clientStatus)
	{
		os << "Desktop: " << clientStatus.Desktop
			<< "Mobile: " << clientStatus.Mobile
			<< "Web: " << clientStatus.Web;
		return os;
	}
}
