#pragma once

#ifndef _WIN32
#error HyperDiscord is only supporting Windows in the moment
#endif

#include <json.hpp>

#include <functional>
#include <sstream>
#include <thread>
#include <vector>

#include "HTTPClient.h"
#include "WebSocketClient.h"
#include "Core/Token.h"
#include "Events/Event.h"
#include "Objects/Message.h"
#include "Objects/Snowflake.h"
#include "Objects/User.h"
#include "Objects/GuildMember.h"
#include "Utilities/Iso8601.h"

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

		std::unordered_map<std::string, EventType> m_EventTypes;
		std::vector<std::function<void(Event&)>>& m_EventFunctions;

		HTTPClient* m_HTTPClient;
		WebSocketClient* m_WebSocketClient;

	public:
		NetworkClient(Token token, std::vector<std::function<void(Event&)>>& eventFunctions);
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

		void OnEvent(EventType eventType, const nlohmann::json& data);

		bool GetBooleanObject(const nlohmann::json& dataArray, const std::string& key);
		std::string GetStringObject(const nlohmann::json& dataArray, const std::string& key);
		Snowflake GetSnowflakeObject(const nlohmann::json& dataArray, const std::string& key);
		Iso8601 GetIso8061Object(const nlohmann::json& dataArray, const std::string& key);
		User GetUserObject(const nlohmann::json& dataArray, const std::string& key);
		GuildMember GetGuildMemberObject(const nlohmann::json& dataArray, const std::string& key);
		Message GetMessageObject(const nlohmann::json& dataArray, const std::string& key);
	};
}
