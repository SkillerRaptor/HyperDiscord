#pragma once

#include <string>
#include <vector>

namespace HyperDiscord
{
	struct HTTPResponse
	{
		std::string Method;
		std::string Path;
		std::vector<std::string> Headers;
		std::string Body;
	};
}
