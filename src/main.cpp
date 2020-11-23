#include "HyperDiscord/HyperDiscord.h"

#include "Networking/WebSocketClient.h"
#include "Events/MessageEvents.h"

using namespace HyperDiscord;

#include <thread>

int main(int argc, char** argv)
{
	HyperClient* hyperClient = new HyperClient("Your Token here!", TokenType::BOT);

	/* NOTE: Pseudo Code */

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
