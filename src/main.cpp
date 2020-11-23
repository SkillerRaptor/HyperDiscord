#include "HyperDiscord/HyperDiscord.h"

#include "Events/MessageEvents.h"

using namespace HyperDiscord;

int main(int argc, char** argv)
{
	HyperClient* hyperClient = new HyperClient("Your Token here!", TokenType::BOT);

	/* NOTE: Pseudo Implementation Code */

	hyperClient->OnEvent([&](Event& event)
		{
			EventDispatcher dispatcher(event);
			dispatcher.Dispatch<MessageCreateEvent>([&](MessageCreateEvent& messageCreateEvent)
				{
					std::cout << "Message Create" << std::endl;
					return true;
				});

			dispatcher.Dispatch<MessageUpdateEvent>([&](MessageUpdateEvent& messageUpdateEvent)
				{
					std::cout << "Message Update" << std::endl;
					return true;
				});

			dispatcher.Dispatch<MessageDeleteEvent>([&](MessageDeleteEvent& messageDeleteEvent)
				{
					std::cout << "Message Delete" << std::endl;
					return true;
				});
		});

	while (true)
	{
		hyperClient->Update();
	}
}
