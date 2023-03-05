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

	Users(T1 login, T1 password, T1 name, bool online) :login_(login), password_(password), online_(online) {};
	Users() = default;
	~Users() {};
};