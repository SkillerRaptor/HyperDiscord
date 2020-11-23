#pragma once

#ifndef _WIN32
#error HyperDiscord is only supporting Windows in the moment
#endif

#include <Windows.h>
#include <winhttp.h>

#include <string>
#include <vector>

namespace HyperDiscord
{
	using Headers = std::vector<std::pair<std::string, std::string>>;

	class WebSocketClient
	{
	private:
		HINTERNET m_Session;
		HINTERNET m_Connection;
		HINTERNET m_WebSocket;

		std::string m_LastRealMessage;

	public:
		WebSocketClient();
		~WebSocketClient();

		const std::string Listen();
		const std::string SendData(const std::string& message);

	private:
		void Init();
		void Shutdown();
	};
}
