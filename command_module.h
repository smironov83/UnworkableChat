//��������� ��� �������������� �������, ��������������� ����������.
//���� ����� � ���: �����������, ��������������, ����� �� ���������.
//���� ����: �������� ��������� ����, ���������� ������������,
//�������� ������� ���������� ������������, ����� �� ��������.
//�������� ���������. ���������� ������� ���������. 
//ChatBot - ������� �������, ��������� �� ��� ��������� � ����, � ���� ���
//���������. ������ ������. ��������� ����� ���������, �� �������� ���������� 
//����� ���. ����� �� �������� ���������� AI ChatGPT (���� �������� �� �������).

#pragma once
#include "message.h"
#include <iostream>
#include "bad_range.h"


class CommandModule
{
	std::vector<Users<std::string, std::vector<std::string>>> users_;
	Users<std::string, std::vector<std::string>>* user_ = nullptr;
	Message* message_ = nullptr;
	std::vector<std::string> chatBotAnswers_;
	size_t currentUser_ = NULL;
		
	void Registration();
	auto LogIn() -> bool;
	void MessageToAll();
	void MessageToUser();
	void PrintUsers();
	void UserInfo();
	void AnswerChatBot();

public:
	bool worksChat_ = true;
	bool worksUser_ = false;

	CommandModule();
	~CommandModule();
	auto LoginMenu() -> bool;
	void InitChatBot();
	auto ChatMenu() -> bool;
	void PrintHistory();
};