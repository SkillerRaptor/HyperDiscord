#include "HyperDiscord/HyperDiscord.h"

using namespace HyperDiscord;

int main(int argc, char** argv)
{
	HyperClient* hyperClient = new HyperClient("Your Token here!", TokenType::BOT);
	hyperClient->Run();
	while (true)
	{
		hyperClient->Update();
	}
}
