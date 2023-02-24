#pragma once
#include <string>

class Users
{
	const std::string _login;
	const std::string _password;
public:
	const std::string _nickname;
	bool _online = false;
	Users(const std::string login, const std::string password, const std::string nickname, bool online);
	~Users();
};