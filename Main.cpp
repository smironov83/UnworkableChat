#include <stdlib.h>
#include "command_module.h"
#include "vld.h"

auto main() -> int
{
	system("chcp 1251");
	system("cls");
	CommandModule unworkableChat;
	unworkableChat.InitChatBot();
	std::cout << "Добро пожаловать в Неработающий Чат!" << std::endl;
	while (unworkableChat.worksChat_)
	{ 
		unworkableChat.LoginMenu();
		while (unworkableChat.worksUser_) 
		{
			unworkableChat.PrintHistory();
			unworkableChat.ChatMenu();
		} 
	}
	return 0;
}
