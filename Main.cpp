#include <stdlib.h>
#include "command_module.h"

//�������� ����. �������������� ���������� ������� ����������
//�������� ������ � �������. ��������� ChatBot'�. ������� ��
//���� ������. ���������� �������� �� ��������� �������� false
//��� ������ �� ���� ����. ������� �� ��������� false ��� ������ 
//�� ���� �����.

auto main() -> int
{
	system("chcp 1251");
	system("cls");
	srand(time(0)); //������ ������ ���������
	CommandModule unworkableChat;
	unworkableChat.InitChatBot();
	std::cout << "����� ���������� � ������������ ���!" << std::endl;
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
