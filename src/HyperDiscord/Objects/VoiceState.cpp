#include "VoiceState.h"

namespace HyperDiscord
{
	VoiceState::VoiceState(Snowflake guildId, Snowflake channelId, Snowflake userId, GuildMember member, const std::string& sessionId, bool deaf, bool mute, bool selfDeaf, bool selfMute, bool selfStream, bool selfVideo, bool suppress)
		: m_GuildId(guildId), m_ChannelId(channelId), m_UserId(userId), m_Member(member), m_SessionId(sessionId), m_Deaf(deaf), m_Mute(mute), m_SelfDeaf(selfDeaf), m_SelfMute(selfMute), m_SelfStream(selfStream), m_SelfVideo(selfVideo), m_Suppress(suppress)
	{
	}

	void VoiceState::SetGuildId(Snowflake guildId)
	{
		m_GuildId = guildId;
	}

	Snowflake VoiceState::GetGuildId() const
	{
		return m_GuildId;
	}

	void VoiceState::SetChannelId(Snowflake channelId)
	{
		m_ChannelId = channelId;
	}

	Snowflake VoiceState::GetChannelId() const
	{
		return m_ChannelId;
	}

	void VoiceState::SetUserId(Snowflake userId)
	{
		m_UserId = userId;
	}

	Snowflake VoiceState::GetUserId() const
	{
		return m_UserId;
	}

	void VoiceState::SetMember(GuildMember member)
	{
		m_Member = member;
	}

	GuildMember VoiceState::GetMember() const
	{
		return m_Member;
	}

	void VoiceState::SetSessionId(const std::string& sessionId)
	{
		m_SessionId = sessionId;
	}

	const std::string& VoiceState::GetSessionId() const
	{
		return m_SessionId;
	}

	void VoiceState::SetDeaf(bool deaf)
	{
		m_Deaf = deaf;
	}

	bool VoiceState::IsDeaf() const
	{
		return m_Deaf;
	}

	void VoiceState::SetMute(bool mute)
	{
		m_Mute = mute;
	}

	bool VoiceState::IsMute() const
	{
		return m_Mute;
	}

	void VoiceState::SetSelfDeaf(bool selfDeaf)
	{
		m_SelfDeaf = selfDeaf;
	}

	bool VoiceState::IsSelfDeaf() const
	{
		return m_SelfDeaf;
	}

	void VoiceState::SetSelfMute(bool selfMute)
	{
		m_SelfMute = selfMute;
	}

	bool VoiceState::IsSelfMute() const
	{
		return m_SelfMute;
	}

	void VoiceState::SetSelfStream(bool selfStream)
	{
		m_SelfStream = selfStream;
	}

	bool VoiceState::IsSelfStream() const
	{
		return m_SelfStream;
	}

	void VoiceState::SetSelfVideo(bool selfVideo)
	{
		m_SelfVideo = selfVideo;
	}

	bool VoiceState::IsSelfVideo() const
	{
		return m_SelfVideo;
	}

	void VoiceState::SetSuppress(bool suppress)
	{
		m_Suppress = suppress;
	}

	bool VoiceState::IsSuppress() const
	{
		return m_Suppress;
	}
}
