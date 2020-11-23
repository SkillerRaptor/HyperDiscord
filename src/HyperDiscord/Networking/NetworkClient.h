#pragma once

#ifndef _WIN32
#error HyperDiscord is only supporting Windows in the moment
#endif

#include <sstream>
#include <thread>

#include "HTTPClient.h"
#include "WebSocketClient.h"
#include "Core/Token.h"

namespace HyperDiscord
{
	class NetworkClient
	{
	private:
		Token m_Token;
		std::thread m_ListeningThread;
		std::thread m_HeartBeatingThread;
		bool m_Running = true;
		uint32_t m_HeartBeat = 0;
		uint32_t m_LastSequenceNumber = 0;

		HTTPClient* m_HTTPClient;
		WebSocketClient* m_WebSocketClient;

	public:
		NetworkClient(Token token);
		~NetworkClient();

		const std::string Get(const std::string& path);
		const std::string Get(const std::string& path, const Headers& headers);

		const std::string Post(const std::string& path);
		const std::string Post(const std::string& path, const std::string& body);
		const std::string Post(const std::string& path, const Headers& headers, const std::string& body);

		const std::string Put(const std::string& path);
		const std::string Put(const std::string& path, const std::string& body);
		const std::string Put(const std::string& path, const Headers& headers, const std::string& body);

		const std::string Patch(const std::string& path);
		const std::string Patch(const std::string& path, const std::string& body);
		const std::string Patch(const std::string& path, const Headers& headers, const std::string& body);

		const std::string Delete(const std::string& path);
		const std::string Delete(const std::string& path, const std::string& body);
		const std::string Delete(const std::string& path, const Headers& headers, const std::string& body);

		const std::string Listen();
		const std::string SendData(const std::string& message);

	private:
		void Listening();
		void HeartBeating();
	};
}
