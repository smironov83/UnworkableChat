#pragma once
#include "message.h"
#include <iostream>


class CommandModule
{
public:
	Users<std::string, std::vector<std::string>>* user_ = nullptr;
	std::vector<Users<std::string, std::vector<std::string>>> users_;
	size_t currentUser_ = NULL;
	Message* message_ = nullptr;
	bool worksChat_ = true;
	bool worksUser_ = false;

	CommandModule();
	~CommandModule();
	auto LoginMenu() -> bool;
	void InitChatBot();
	void Registration();
	auto LogIn() -> bool;
	auto ChatMenu() -> bool;
	void MessageToAll();
	void PrintHistory();
	void MessageToUser();
	void PrintUsers();
	void UserInfo();
	void AnswerChatBot();
};