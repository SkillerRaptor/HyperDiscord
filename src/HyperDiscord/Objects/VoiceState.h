#pragma once

#include <iostream>
#include <string>

#include "GuildMember.h"
#include "Snowflake.h"

namespace HyperDiscord
{
	class VoiceState
	{
	private:
		Snowflake m_GuildId;
		Snowflake m_ChannelId;
		Snowflake m_UserId;
		GuildMember m_Member;
		std::string m_SessionId;
		bool m_Deaf;
		bool m_Mute;
		bool m_SelfDeaf;
		bool m_SelfMute;
		bool m_SelfStream;
		bool m_SelfVideo;
		bool m_Suppress;

	public:
		VoiceState(Snowflake guildId, Snowflake channelId, Snowflake userId, GuildMember member, const std::string& sessionId, bool deaf, bool mute, bool selfDeaf, bool selfMute, bool selfStream, bool selfVideo, bool suppress);

		void SetGuildId(Snowflake guildId);
		Snowflake GetGuildId() const;

		void SetChannelId(Snowflake channelId);
		Snowflake GetChannelId() const;

		void SetUserId(Snowflake userId);
		Snowflake GetUserId() const;

		void SetMember(GuildMember member);
		GuildMember GetMember() const;

		void SetSessionId(const std::string& sessionId);
		const std::string& GetSessionId() const;

		void SetDeaf(bool deaf);
		bool IsDeaf() const;

		void SetMute(bool mute);
		bool IsMute() const;

		void SetSelfDeaf(bool selfDeaf);
		bool IsSelfDeaf() const;

		void SetSelfMute(bool selfMute);
		bool IsSelfMute() const;

		void SetSelfStream(bool selfStream);
		bool IsSelfStream() const;

		void SetSelfVideo(bool selfVideo);
		bool IsSelfVideo() const;

		void SetSuppress(bool suppress);
		bool IsSuppress() const;

		friend std::ostream& operator<<(std::ostream& os, const VoiceState& voiceState);
	};

	inline std::ostream& operator<<(std::ostream& os, const VoiceState& voiceState)
	{
		os << "Guild Id: " << voiceState.GetGuildId()
			<< ", Channel Id: " << voiceState.GetChannelId()
			<< ", User Id: " << voiceState.GetUserId()
			<< ", Member: " << voiceState.GetMember()
			<< ", Session Id: " << voiceState.GetSessionId()
			<< ", Deaf: " << voiceState.IsDeaf()
			<< ", Mute: " << voiceState.IsMute()
			<< ", Self Deaf: " << voiceState.IsSelfDeaf()
			<< ", Self Mute: " << voiceState.IsSelfMute()
			<< ", Self Stream: " << voiceState.IsSelfStream()
			<< ", Self Video: " << voiceState.IsSelfVideo()
			<< ", Suppress: " << voiceState.IsSuppress();
		return os;
	}
}
