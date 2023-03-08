//Шаблонный класс пользователей. Описаны значения: логин, пароль, имя, статус 
//нахождения в сети, история переписки.
//Реализация в заголовочном файле.

#pragma once
#include <vector>
#include <string>

template <typename T1, typename T2>	class Users
{
public:
	T1 login_;
	T1 password_;
	T1 name_;
	bool online_ = false;
	T2 history_;

	Users(T1 login, T1 password, T1 name, bool online) :login_(login), 
		password_(password), name_(name), online_(online) {};
	Users() = default;
	~Users() {};
};