#pragma once

#ifndef _WIN32
#error HyperDiscord is only supporting Windows in the moment
#endif

/* Core */
#include "Core/HyperClient.h"
#include "Core/Token.h"

/* Managers */
#include "Managers/ChannelManager.h"
#include "Managers/EmojiManager.h"
#include "Managers/GuildManager.h"

/* Events */
#include "Events/Event.h"
#include "Events/GuildEvents.h"
#include "Events/MessageEvents.h"

/* Networking */
#include "Networking/HTTPClient.h"
#include "Networking/NetworkClient.h"
#include "Networking/WebsocketClient.h"
#include "Networking/Gateway/Activity.h"
#include "Networking/Gateway/ActivityAssets.h"
#include "Networking/Gateway/ActivityEmoji.h"
#include "Networking/Gateway/ActivityParty.h"
#include "Networking/Gateway/ActivitySecrets.h"
#include "Networking/Gateway/ActivityTimestamp.h"
#include "Networking/Gateway/ClientStatus.h"
#include "Networking/Gateway/PresenceUpdate.h"

/* Objects */
#include "Objects/Channel.h"
#include "Objects/Emoji.h"
#include "Objects/Guild.h"
#include "Objects/GuildMember.h"
#include "Objects/Message.h"
#include "Objects/Overwrite.h"
#include "Objects/Role.h"
#include "Objects/Snowflake.h"
#include "Objects/VoiceRegion.h"
#include "Objects/VoiceState.h"

/* Utilities */
#include "Utilities/Discord.h"
#include "Utilities/Iso8601.h"
#include "Utilities/Timestamp.h"
