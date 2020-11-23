#pragma once

#ifndef _WIN32
#error HyperDiscord is only supporting Windows in the moment
#endif

#include <iostream>
#include <string>

namespace HyperDiscord
{
	/* https://discord.com/developers/docs/topics/gateway#activity-object-activity-assets */
	struct ActivityAssets
	{
		std::string LargeImage;
		std::string LargeText;
		std::string SmallImage;
		std::string SmallText;

		friend std::ostream& operator<<(std::ostream& os, const ActivityAssets& activityAssets);
	};

	inline std::ostream& operator<<(std::ostream& os, const ActivityAssets& activityAssets)
	{
		os << "Large Image: " << activityAssets.LargeImage
			<< ", Large Text: " << activityAssets.LargeText
			<< ", Small Image: " << activityAssets.SmallImage
			<< ", Small Text: " << activityAssets.SmallText;
		return os;
	}
}
