#pragma once

#ifndef _WIN32
#error HyperDiscord is only supporting Windows in the moment
#endif

#include <iostream>
#include <string>

#include "GuildMember.h"
#include "Snowflake.h"

namespace HyperDiscord
{
	/* https://discord.com/developers/docs/resources/voice#voice-state-object-voice-state-structure */
	struct VoiceState
	{
		Snowflake GuildId;
		Snowflake ChannelId;
		Snowflake UserId;
		GuildMember Member;
		std::string SessionId;
		bool Deaf;
		bool Mute;
		bool SelfDeaf;
		bool SelfMute;
		bool SelfStream;
		bool SelfVideo;
		bool Suppress;

		friend std::ostream& operator<<(std::ostream& os, const VoiceState& voiceState);
	};

	inline std::ostream& operator<<(std::ostream& os, const VoiceState& voiceState)
	{
		os << "Guild Id: " << voiceState.GuildId
			<< ", Channel Id: " << voiceState.ChannelId
			<< ", User Id: " << voiceState.UserId
			<< ", Member: " << voiceState.Member
			<< ", Session Id: " << voiceState.SessionId
			<< ", Deaf: " << voiceState.Deaf
			<< ", Mute: " << voiceState.Mute
			<< ", Self Deaf: " << voiceState.SelfDeaf
			<< ", Self Mute: " << voiceState.SelfMute
			<< ", Self Stream: " << voiceState.SelfStream
			<< ", Self Video: " << voiceState.SelfVideo
			<< ", Suppress: " << voiceState.Suppress;
		return os;
	}
}
