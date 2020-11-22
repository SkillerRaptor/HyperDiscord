#include "HTTPClient.hpp"

#include <iostream>

namespace HyperDiscord
{
	HTTPClient::HTTPClient(const std::string& host, uint16_t port)
		: m_HostAddress(host), m_Port(port)
	{
		Init();
	}

	HTTPClient::~HTTPClient()
	{
		Shutdown();
	}

	void HTTPClient::Init()
	{
		if (WSAStartup(MAKEWORD(2, 2), &m_Data) != 0)
		{
			std::cout << "[HyperDiscord] Failed to run WSAStartup." << std::endl;
			exit(-1);
		}

		m_Host = gethostbyname(m_HostAddress.c_str());
		m_Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		m_SocketAddress.sin_port = htons(m_Port);
		m_SocketAddress.sin_family = AF_INET;
		m_SocketAddress.sin_addr.S_un.S_addr = *(unsigned long*)m_Host->h_addr_list[0];

		if (connect(m_Socket, (SOCKADDR*)(&m_SocketAddress), sizeof(m_SocketAddress)) != 0)
		{
			std::cout << "[HyperDiscord] Failed to connect with a Socket." << std::endl;
			exit(-1);
		}
	}

	void HTTPClient::Shutdown()
	{
		closesocket(m_Socket);
		WSACleanup();
	}

	HTTPResult HTTPClient::Get(const std::string& path)
	{
		std::string request = GenerateRequestString("GET", path);

		send(m_Socket, request.c_str(), strlen(request.c_str()), 0);

		std::cout << GenerateRequestString("GET", path) << std::endl;

		char body[2000];
		int receiveSize;
		if ((receiveSize = recv(m_Socket, body, 2000, 0)) == SOCKET_ERROR)
		{
			std::cout << "[HyperDiscord] Failed receive data." << std::endl;
			exit(-1);
		}

		body[receiveSize] = '\0';
		std::cout << body << std::endl;

		return HTTPResult(std::make_unique<HTTPResponse>(), HTTPResult::HTTPError::UNKNOWN);
	}

	HTTPResult HTTPClient::Post(const std::string& path)
	{
		return HTTPResult(std::make_unique<HTTPResponse>(), HTTPResult::HTTPError::UNKNOWN);
	}

	HTTPResult HTTPClient::Post(const std::string& path, const std::string& body, const std::string& contentType)
	{
		return HTTPResult(std::make_unique<HTTPResponse>(), HTTPResult::HTTPError::UNKNOWN);
	}

	HTTPResult HTTPClient::Put(const std::string& path)
	{
		return HTTPResult(std::make_unique<HTTPResponse>(), HTTPResult::HTTPError::UNKNOWN);
	}

	HTTPResult HTTPClient::Put(const std::string& path, const std::string& body, const std::string& contentType)
	{
		return HTTPResult(std::make_unique<HTTPResponse>(), HTTPResult::HTTPError::UNKNOWN);
	}

	HTTPResult HTTPClient::Delete(const std::string& path)
	{
		return HTTPResult(std::make_unique<HTTPResponse>(), HTTPResult::HTTPError::UNKNOWN);
	}

	HTTPResult HTTPClient::Delete(const std::string& path, const std::string& body, const std::string& contentType)
	{
		return HTTPResult(std::make_unique<HTTPResponse>(), HTTPResult::HTTPError::UNKNOWN);
	}

	const std::string HTTPClient::GenerateRequestString(const std::string& requestType, const std::string& path)
	{
		std::string request;
		request += requestType + " " + path + " HTTP/1.1\r\n";
		request += "Host: " + m_HostAddress + "\r\n";
		request += "User-Agent: Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/53.0.2785.143 Safari/537.36\r\n";
		request += "\r\n";
		return request;
	}
}
