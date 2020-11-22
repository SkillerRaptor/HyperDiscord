#include "NetworkClient.h"

namespace HyperDiscord
{
	NetworkClient::NetworkClient(Token token)
		: m_Token(token), m_HTTPClient(m_Token), m_WebSocketClient()
	{
	}

	NetworkClient::~NetworkClient()
	{
	}

	const std::string NetworkClient::Get(const std::string& path)
	{
		return m_HTTPClient.Get(path);
	}

	const std::string NetworkClient::Get(const std::string& path, const Headers& headers)
	{
		return m_HTTPClient.Get(path, headers);
	}

	const std::string NetworkClient::Post(const std::string& path)
	{
		return m_HTTPClient.Post(path);
	}

	const std::string NetworkClient::Post(const std::string& path, const std::string& body)
	{
		return m_HTTPClient.Post(path, body);
	}

	const std::string NetworkClient::Post(const std::string& path, const Headers& headers, const std::string& body)
	{
		return m_HTTPClient.Post(path, headers, body);
	}

	const std::string NetworkClient::Put(const std::string& path)
	{
		return m_HTTPClient.Put(path);
	}

	const std::string NetworkClient::Put(const std::string& path, const std::string& body)
	{
		return m_HTTPClient.Put(path, body);
	}

	const std::string NetworkClient::Put(const std::string& path, const Headers& headers, const std::string& body)
	{
		return m_HTTPClient.Put(path, headers, body);
	}

	const std::string NetworkClient::Patch(const std::string& path)
	{
		return m_HTTPClient.Patch(path);
	}

	const std::string NetworkClient::Patch(const std::string& path, const std::string& body)
	{
		return m_HTTPClient.Patch(path, body);
	}

	const std::string NetworkClient::Patch(const std::string& path, const Headers& headers, const std::string& body)
	{
		return m_HTTPClient.Patch(path, headers, body);
	}

	const std::string NetworkClient::Delete(const std::string& path)
	{
		return m_HTTPClient.Delete(path);
	}

	const std::string NetworkClient::Delete(const std::string& path, const std::string& body)
	{
		return m_HTTPClient.Delete(path, body);
	}

	const std::string NetworkClient::Delete(const std::string& path, const Headers& headers, const std::string& body)
	{
		return m_HTTPClient.Delete(path, headers, body);
	}
}
