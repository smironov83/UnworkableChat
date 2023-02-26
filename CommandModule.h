#pragma once
#include <iostream>
#include "Message.h"


class CommandModule
{
public:
	Users* _user = nullptr;
	std::vector<Users> _users;
	int _currentUser = NULL;
	Message t;

	~CommandModule();
	auto LoginMenu()->size_t;
	void InitChatBot();
	void Registration();
	auto LogIn() -> bool;
	auto ChatMenu() -> size_t;
};