#pragma once
#include "users.h"
#include <time.h>

struct Message
{
	std::string to_, text_, from_, timeStamp_;
	
	Message(std::string timeStamp, std::string from, std::string to, std::string text);
	~Message();

	auto TimeStamp() -> std::string;
	auto MessageConstructor() -> std::string;
};