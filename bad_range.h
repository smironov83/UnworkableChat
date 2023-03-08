//ќбрабатывает исключение возможного выхода за пределы массива
//автоматических ответов ChatBot'а в случае изменени€ количества фраз
//без соответствующего изменени€ диапазона генерации случайных чисел.
//–еализаци€ в заголовочном файле.

#pragma once
#include <exception>

struct bad_range :public std::exception
{
	virtual const char* what() const noexcept override
	{
		return "ERROR:!!!¬ыход за пределы словарного запаса ChatBot'а!!!";
	}
};