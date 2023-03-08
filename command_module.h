//Реализует все функциональные команды, предусмотренные программой.
//Меню входа в чат: регистрация, аутентификация, выход из программы.
//Меню чата: отправка сообщений всем, выбранному пользователю,
//просмотр профиля выбранного пользователя, выход из аккаунта.
//Отправка сообщений. Сохранение истории сообщений. 
//ChatBot - принцип попугая, реагирует на все сообщения в чате, в зоне его
//видимости. Всегда онлайн. Словарный запас ограничен, но доступно расширение 
//через код. Задел на будущего конкурента AI ChatGPT (пока времение не хватило).

#pragma once
#include "message.h"
#include <iostream>
#include "bad_range.h"


class CommandModule
{
	std::vector<Users<std::string, std::vector<std::string>>> users_;
	Users<std::string, std::vector<std::string>>* user_ = nullptr;
	Message* message_ = nullptr;
	std::vector<std::string> chatBotAnswers_;
	size_t currentUser_ = NULL;
		
	void Registration();
	auto LogIn() -> bool;
	void MessageToAll();
	void MessageToUser();
	void PrintUsers();
	void UserInfo();
	void AnswerChatBot();

public:
	bool worksChat_ = true;
	bool worksUser_ = false;

	CommandModule();
	~CommandModule();
	auto LoginMenu() -> bool;
	void InitChatBot();
	auto ChatMenu() -> bool;
	void PrintHistory();
};