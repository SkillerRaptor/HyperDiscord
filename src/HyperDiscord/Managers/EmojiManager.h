#pragma once

#ifndef _WIN32
#error HyperDiscord is only supporting Windows in the moment
#endif

#include "Utilities/NonCopyable.h"
#include "Utilities/NonMoveable.h"

namespace HyperDiscord
{
	class EmojiManager : public NonCopyable, NonMoveable
	{
	private:

	public:
		EmojiManager();
	};
}
