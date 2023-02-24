#include "CommandModule.h"

auto CommandModule::LoginMenu()
{
	auto commandNumber = NULL;
	std::cout << "����� ���������� � ������������ ���!" << std::endl;
	std::cout << "��� ����������� ������� ����� ������ ��������:" << std::endl;
	std::cout << "1 - ����� � ���" << std::endl;
	std::cout << "2 - ������������������ � ����" << std::endl;
	std::cout << "3 - ����� �� ����" << std::endl;
	while ((std::cin.peek() != '\n') || !(commandNumber == 1 || commandNumber == 2 || commandNumber == 3))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "�� ����� �������� ����� ��������. ����������, ��������� ����!" << std::endl;
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
