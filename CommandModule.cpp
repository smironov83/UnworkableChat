#include "CommandModule.h"

auto CommandModule::LoginMenu()
{
	auto commandNumber = NULL;
	std::cout << "Добро пожаловать в Неработающий чат!" << std::endl;
	std::cout << "Для продолжения введите номер нужной комманды:" << std::endl;
	std::cout << "1 - войти в чат" << std::endl;
	std::cout << "2 - зарегистрироваться в чате" << std::endl;
	std::cout << "3 - выйти из чата" << std::endl;
	while ((std::cin.peek() != '\n') || !(commandNumber == 1 || commandNumber == 2 || commandNumber == 3))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Вы ввели неверный номер комманды. Пожалуйста, повторите ввод!" << std::endl;
	}
	switch (commandNumber)
	{
	case 1:
		snackBuy = bounty->get_title();
		break;
	case 2:
		snackBuy = snickers->get_title();
		break;
	case 3:
		snackBuy = snickers->get_title();
		break;
	}
	return commandNumber;
}
