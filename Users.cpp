#include "Users.h"

Users::Users(std::string login, std::string password, std::string name, bool online, History* history) :
	_login(login), password_(password), _name(name), _online(online), history_(history) {};
 
Users::~Users() {};