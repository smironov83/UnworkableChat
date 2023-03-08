#include <stdlib.h>
#include "command_module.h"

//Основной блок. Инициализирует переменную классом реализации
//основных команд и функций. Запускает ChatBot'а. Состоит из
//двух циклов. Внутренний работает до получения значения false
//при выходы из меню чата. Внешний до получения false при выходе 
//из меню входа.

auto main() -> int
{
	system("chcp 1251");
	system("cls");
	srand(time(0)); //Делает рандом рандомным
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
