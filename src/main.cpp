#include "HyperDiscord/HyperDiscord.h"

#include "Events/GuildEvents.h"
#include "Events/MessageEvents.h"

using namespace HyperDiscord;

int main(int argc, char** argv)
{
	HyperClient* hyperClient = new HyperClient("Your Token here!", TokenType::BOT);

	/* NOTE: Pseudo Implementation Code */

	hyperClient->OnEvent([&](Event& event)
		{
			EventDispatcher dispatcher(event);
			dispatcher.Dispatch<GuildCreateEvent>([&](GuildCreateEvent& guildCreateEvent)
				{
					std::cout << "Guild Create" << std::endl;
				});

			dispatcher.Dispatch<MessageCreateEvent>([&](MessageCreateEvent& messageCreateEvent)
				{
					std::cout << "Message Create" << std::endl;
				});

			dispatcher.Dispatch<MessageUpdateEvent>([&](MessageUpdateEvent& messageUpdateEvent)
				{
					std::cout << "Message Update" << std::endl;
				});

			dispatcher.Dispatch<MessageDeleteEvent>([&](MessageDeleteEvent& messageDeleteEvent)
				{
					std::cout << "Message Delete" << std::endl;
				});
		});

	while (true)
	{
		hyperClient->Update();
	}
}
