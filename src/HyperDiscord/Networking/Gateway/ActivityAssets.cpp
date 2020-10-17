#include "ActivityEmoji.h"
#include "ActivityAssets.h"

namespace HyperDiscord
{
	ActivityAssets::ActivityAssets(const std::string& largeImage, const std::string& largeText, const std::string& smallImage, const std::string& smallText)
		: m_LargeImage(largeImage), m_LargeText(largeText), m_SmallImage(smallImage), m_SmallText(smallText)
	{
	}

	void ActivityAssets::SetLargeImage(const std::string& largeImage)
	{
		m_LargeImage = largeImage;
	}

	const std::string& ActivityAssets::GetLargeImage() const
	{
		return m_LargeImage;
	}

	void ActivityAssets::SetLargeText(const std::string& largeText)
	{
		m_LargeText = largeText;
	}

	const std::string& ActivityAssets::GetLargeText() const
	{
		return m_LargeText;
	}

	void ActivityAssets::SetSmallImage(const std::string& smallImage)
	{
		m_SmallImage = smallImage;
	}

	const std::string& ActivityAssets::GetSmallImage() const
	{
		return m_SmallImage;
	}

	void ActivityAssets::SetSmallText(const std::string& smallText)
	{
		m_SmallText = smallText;
	}

	const std::string& ActivityAssets::GetSmallText() const
	{
		return m_SmallText;
	}
}
