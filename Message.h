//ѕреобразует входные данные в единую строку 
//с добавлением текущего системного времени.

#pragma once
#include "users.h"
#include <time.h>

struct Message
{
	std::string const to_, text_, from_, timeStamp_;
	
	Message(std::string const timeStamp, std::string const from, std::string const to, std::string const text);
	~Message();

	auto TimeStamp() -> std::string const;
	auto MessageConstructor() -> std::string const;
};