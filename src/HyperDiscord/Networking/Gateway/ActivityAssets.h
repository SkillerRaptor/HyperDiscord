#pragma once

#ifndef _WIN32
#error HyperDiscord is only supporting Windows in the moment
#endif

#include <iostream>
#include <string>

namespace HyperDiscord
{
	/* https://discord.com/developers/docs/topics/gateway#activity-object-activity-assets */
	class ActivityAssets
	{
	private:
		std::string m_LargeImage;
		std::string m_LargeText;
		std::string m_SmallImage;
		std::string m_SmallText;

	public:
		ActivityAssets(const std::string& largeImage, const std::string& largeText, const std::string& smallImage, const std::string& smallText);

		void SetLargeImage(const std::string& largeImage);
		const std::string& GetLargeImage() const;

		void SetLargeText(const std::string& largeText);
		const std::string& GetLargeText() const;

		void SetSmallImage(const std::string& smallImage);
		const std::string& GetSmallImage() const;

		void SetSmallText(const std::string& smallText);
		const std::string& GetSmallText() const;

		friend std::ostream& operator<<(std::ostream& os, const ActivityAssets& activityAssets);
	};

	inline std::ostream& operator<<(std::ostream& os, const ActivityAssets& activityAssets)
	{
		os << "Large Image: " << activityAssets.GetLargeImage()
			<< ", Large Text: " << activityAssets.GetLargeText()
			<< ", Small Image: " << activityAssets.GetSmallImage()
			<< ", Small Text: " << activityAssets.GetSmallText();
		return os;
	}
}
