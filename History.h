#pragma once
#include <string>
#include <vector>

template <typename T> class History
{
	T historyMessages_;
public:
	History(T history) :historyMessages_(history) {};
	History() = default;
	~History() {};
};
