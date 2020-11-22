#include "HyperDiscord/HyperDiscord.h"

using namespace HyperDiscord;

int main(int argc, char** argv)
{
	HyperClient* hyperClient = new HyperClient("Your Token here!", TokenType::BOT);
	while (true)
	{
		hyperClient->Update();
	}
}
