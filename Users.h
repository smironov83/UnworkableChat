#pragma once
#include "History.h"

class Users :protected History<std::vector<std::string>>
{
public:
	std::string _login;
	std::string password_;
	std::string _name;
	bool _online = false;
	History* history_;

	Users(std::string login, std::string password, std::string name, bool online, History* history);
	Users() = default;
	~Users();
};