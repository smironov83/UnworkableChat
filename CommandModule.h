#pragma once
#include "Users.h"
#include <vector>

class CommandModule :private Users
{
	std::vector<Users>_users{};
public:
	//void registration();
	//void logon();
	//void logout();
};