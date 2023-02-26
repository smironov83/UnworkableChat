#include <stdlib.h>
#include "CommandModule.h"
#include "vld.h"

auto main() -> int
{
	system("chcp 1251");
	system("cls");
	
	CommandModule unworkableChat;
	unworkableChat.InitChatBot();
	std::cout << "Добро пожаловать в Неработающий Чат!" << std::endl;
	std::cout << unworkableChat.t.timeStamp() << std::endl;
	while (!(unworkableChat.LoginMenu() == 3))
	{
		if (unworkableChat.LoginMenu() == 1)
		{
			while (!(unworkableChat.ChatMenu() == 4))
			{

			}
		}
	}
	return 0;
}
