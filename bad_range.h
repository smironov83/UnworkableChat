#pragma once
#include <exception>

struct bad_range :public std::exception
{
	int badRange_ = NULL;
	virtual const char* what() const noexcept override;
	bad_range();
	~bad_range();
};
