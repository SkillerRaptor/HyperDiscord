#pragma once
#pragma comment(lib,"ws2_32.lib")

#include <string>
#include <WinSock2.h>

#include "HTTPResult.hpp"

namespace HyperDiscord
{
	class HTTPClient
	{
	private:
		std::string m_HostAddress;
		uint16_t m_Port;

		WSADATA m_Data;
		SOCKET m_Socket;
		SOCKADDR_IN m_SocketAddress;
		HOSTENT* m_Host;

	public:
		HTTPClient(const std::string& host, uint16_t port = 443);
		~HTTPClient();

		HTTPResult Get(const std::string& path);

		HTTPResult Post(const std::string& path);
		HTTPResult Post(const std::string& path, const std::string& body, const std::string& contentType);

		HTTPResult Put(const std::string& path);
		HTTPResult Put(const std::string& path, const std::string& body, const std::string& contentType);

		HTTPResult Delete(const std::string& path);
		HTTPResult Delete(const std::string& path, const std::string& body, const std::string& contentType);

	private:
		void Init();
		void Shutdown();

		const std::string GenerateRequestString(const std::string& requestType, const std::string& path);
	};
}
