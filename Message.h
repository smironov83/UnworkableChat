#pragma once
#include "Users.h"
#include <time.h>

struct Message
{
	std::string from_, to_, text_, timeStamp_;
	
	Message();
	~Message();

	auto timeStamp() -> std::string;
};