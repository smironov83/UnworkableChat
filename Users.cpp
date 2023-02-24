#include "Users.h"

Users::Users(const std::string login, const std::string password, const std::string nickname, bool online) :
	_login(login), _password(password), _nickname(nickname), _online(online) {};

Users::~Users() {};