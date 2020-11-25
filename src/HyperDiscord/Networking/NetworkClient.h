#pragma once

#ifndef _WIN32
#error HyperDiscord is only supporting Windows in the moment
#endif

#include <json.hpp>

#include <functional>
#include <memory>
#include <optional>
#include <queue>
#include <sstream>
#include <thread>
#include <vector>

#include "HTTPClient.h"
#include "WebSocketClient.h"
#include "Core/Token.h"
#include "Events/Event.h"
#include "Objects/Guild.h"
#include "Objects/GuildMember.h"
#include "Objects/Message.h"
#include "Objects/Snowflake.h"
#include "Objects/User.h"
#include "Utilities/Iso8601.h"

namespace HyperDiscord
{
	enum Intent : uint16_t
	{
		NOTHING = 1 << 15,
		GUILDS = 1 << 0,
		GUILD_MEMBERS = 1 << 1,
		GUILD_BANS = 1 << 2,
		GUILD_EMOJIS = 1 << 3,
		GUILD_INTEGRATIONS = 1 << 4,
		GUILD_WEBHOOKS = 1 << 5,
		GUILD_INVITES = 1 << 6,
		GUILD_VOICE_STATES = 1 << 7,
		GUILD_PRESENCES = 1 << 8,
		GUILD_MESSAGES = 1 << 9,
		GUILD_MESSAGE_REACTIONS = 1 << 10,
		GUILD_MESSAGE_TYPING = 1 << 11,
		DIRECT_MESSAGES = 1 << 12,
		DIRECT_MESSAGE_REACTIONS = 1 << 13,
		DIRECT_MESSAGE_TYPING = 1 << 14
	};

	inline Intent operator|(Intent left, Intent right)
	{
		return static_cast<Intent>(static_cast<uint16_t>(left) | static_cast<uint16_t>(right));
	}

	class NetworkClient
	{
	private:
		Token m_Token;
		Intent m_Intents;
		std::thread m_ListeningThread;
		std::thread m_HeartBeatingThread;
		bool m_Running = true;
		uint32_t m_HeartBeat = 0;
		uint32_t m_LastSequenceNumber = 0;

		std::unordered_map<std::string, EventType> m_EventTypes;
		std::queue<std::shared_ptr<Event>>& m_EventBus;

		HTTPClient* m_HTTPClient;
		WebSocketClient* m_WebSocketClient;

	public:
		NetworkClient(Token token, Intent intents, std::queue<std::shared_ptr<Event>>& eventBus);
		~NetworkClient();

		const std::optional<nlohmann::json> Get(const std::string& path);
		const std::optional<nlohmann::json> Post(const std::string& path, const std::string& body);
		const std::optional<nlohmann::json> Patch(const std::string& path, const std::string& body);
		const std::optional<nlohmann::json> Put(const std::string& path, const std::string& body = "");
		void Delete(const std::string& path);

		const std::string SendData(const std::string& message);

		bool GetBooleanObject(const nlohmann::json& dataArray, const std::string& key = "");
		int GetIntegerObject(const nlohmann::json& dataArray, const std::string& key = "");
		std::string GetStringObject(const nlohmann::json& dataArray, const std::string& key = "");
		nlohmann::json GetArrayObject(const nlohmann::json& dataArray, const std::string& key = "");

		Snowflake GetSnowflakeObject(const nlohmann::json& dataArray, const std::string& key = "");
		Iso8601 GetIso8061Object(const nlohmann::json& dataArray, const std::string& key = "");

		Channel GetChannelObject(const nlohmann::json& dataArray, const std::string& key = "");
		Guild GetGuildObject(const nlohmann::json& dataArray, const std::string& key = "");
		User GetUserObject(const nlohmann::json& dataArray, const std::string& key = "");
		GuildMember GetGuildMemberObject(const nlohmann::json& dataArray, const std::string& key = "");
		Message GetMessageObject(const nlohmann::json& dataArray, const std::string& key = "");

	private:
		void Listening();
		void HeartBeating();

		void OnEvent(EventType eventType, const nlohmann::json& data);
	};
}
