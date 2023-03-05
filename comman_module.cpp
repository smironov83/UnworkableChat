#include "command_module.h"

CommandModule::CommandModule() {}
CommandModule::~CommandModule() {}

auto CommandModule::LoginMenu()->bool
{
	std::cout << std::endl;
	size_t commandNumber = NULL;
	std::cout << "Для продолжения работы введите номер комманды:" << std::endl;
	std::cout << "1 - войти в чат" << std::endl;
	std::cout << "2 - зарегистрироваться в чате:" << std::endl;
	std::cout << "3 - выйти из программы" << std::endl;
	while (!(std::cin >> commandNumber) || (std::cin.peek() != '\n') || !(commandNumber == 1 || commandNumber == 2 || commandNumber == 3))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Вы ввели неверный номер комманды. Пожалуйста, повторите ввод: " << std::endl;
	}
	switch (commandNumber)
	{
	case 1:
		users_[currentUser_].online_ = LogIn();
		worksUser_ = users_[currentUser_].online_;
		break;
	case 2:
		Registration();
		break;
	case 3:
		std::cout << std::endl << "Очень жаль, что Вы покидаете Неработающий Чат! Ждём Вашего возвращения!" << std::endl;
		worksChat_ = false;
		break;
	}
	return worksChat_;
}

void CommandModule::InitChatBot()
{
	user_ = new Users<std::string, std::vector<std::string>>{ "ChatBot", "qwerty", "Bot", true };
	users_.push_back(*user_);
	delete user_;
}

void CommandModule::Registration() 
{
	std::cout << std::endl;
	user_ = new Users<std::string, std::vector<std::string>>{};
	auto unique = true;
	std::cout << "Введите логин: ";
	do
	{
		std::cin >> user_->login_;
		unique = true;
		for (auto& user : users_)
		{
			if (user_->login_ == user.login_)
			{
				unique = false;
				std::cout << "Логин занят. Введите другой логин: ";
			}
		}
	} while (!(unique));
	std::cout << "Введите пароль: ";
	std::cin >> user_->password_;
	std::cout << "Введите Ваше имя: ";
	std::cin >> user_->name_;
	user_->online_ = false;
	users_.push_back(*user_);
	std::cout << "Регистрация успешно завершена. Для продолжения работы войдите в Неработающий Чат под Вашими учетными данными!" << std::endl;
	delete user_;
}

auto CommandModule::LogIn() -> bool
{
	std::cout << std::endl;
	user_ = new Users<std::string, std::vector<std::string>>{};
	std::cout << "Для входа в Неработающий Чат введите Ваши учетные данные!" << std::endl;
	auto unique = true;
	auto online = true;
	do
	{
		do
		{
			auto counter = NULL;
			std::cout << "Введите логин: ";
			std::cin >> user_->login_;
			for (auto& user : users_)
			{
				if (user_->login_ == user.login_)
				{
					unique = false;
					currentUser_ = counter;
				}
				if (unique && (counter == users_.size() - 1)&&(user_->login_!="exit"))
				{ 
					std::cout << "Логин не зарегистрирован. Повторите ввод или введите exit для возврата в предыдущее меню." << std::endl;
				}
				if (user_->login_ == "exit") 
				{
					unique = false;
					online = false;
				}
				counter++;
			}
		} while (unique);
		if (user_->login_ != "exit")
		{
			std::cout << "Введите пароль: ";
			std::cin >> user_->password_;
			if (user_->password_ != users_[currentUser_].password_)
			{
				std::cout << "Пароль неверный. Повторите ввод логина и пароля!" << std::endl;
				unique = true;
			}
		}
	} while (unique);
	delete user_;
	return online;
}

auto CommandModule::ChatMenu() -> bool
{
	size_t command = NULL;
	std::cout << "Выберите действие:" << std::endl;
	std::cout << "1 - написать сообщение всем" << std::endl;
	std::cout << "2 - написать выбранному пользователю:" << std::endl;
	std::cout << "3 - просмотреть профиль выбранного пользователя" << std::endl;
	std::cout << "4 - выйти из чата" << std::endl;
	while (!(std::cin >> command) || (std::cin.peek() != '\n') || !(command == 1 || command == 2 || command == 3 || command == 4))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Вы ввели неверный номер комманды. Пожалуйста, повторите ввод: " << std::endl;
	}
	switch (command)
	{
	case 1:
		MessageToAll();
		break;
	case 2:
		MessageToUser();
		break;
	case 3:
		UserInfo();
		break;
	case 4:
		system("cls");
		std::cout << "Вы вышли из чата!" << std::endl;
		worksUser_ = false;
		users_[currentUser_].online_ = worksUser_;
		break;
	}
	return worksUser_;
}

void CommandModule::MessageToAll()
{
	std::cout << "[" << users_[currentUser_].login_ << "]" << " -> "<<"[All] : ";
	std::string text;
	std::cin.ignore();
	std::getline(std::cin, text);
	message_ = new Message{ message_->TimeStamp(), users_[currentUser_].login_, "All", text };
	for (auto& user : users_) { user.history_.push_back(message_->MessageConstructor()); }
	delete message_;
	AnswerChatBot();
}

void CommandModule::PrintHistory()
{
	system("cls");
	for (auto& user : users_[currentUser_].history_) { std::cout << user << std::endl; };
}

void CommandModule::MessageToUser()
{
	PrintUsers();
	std::cout << "Введите номер пользователя, которому Вы хотите отправить сообщение: ";
	size_t command = 0;
	while (!(std::cin >> command) || (std::cin.peek() != '\n') || (command == 0) || !(command < users_.size() + 1))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Вы ввели неверный номер комманды. Пожалуйста, повторите ввод: " << std::endl;
	}
	std::cout << "[" << users_[currentUser_].login_ << "]" << " -> " << "[" << users_[--command].login_ << "]" << " : ";
	std::string text;
	std::cin.ignore();
	std::getline(std::cin, text);
	message_ = new Message{ message_->TimeStamp(), users_[currentUser_].login_, users_[command].login_, text};
	users_[currentUser_].history_.push_back(message_->MessageConstructor());
	if (command != currentUser_) { users_[command].history_.push_back(message_->MessageConstructor()); }
	delete message_;
	if (users_[command].login_ == "ChatBot") { AnswerChatBot(); }
}

void CommandModule::PrintUsers() 
{
	size_t counter = 0;
	for (auto& user: users_)
	{
		++counter;
		std::cout << counter << " - " << user.login_;
		if (user.online_) { std::cout << " (online) "; }
		else { std::cout << " (offline) "; }
		std::cout << std::endl;
	}
}

void CommandModule::UserInfo()
{
	PrintUsers();
	std::cout << "Введите номер пользователя, профиль которого Вы хотите посмотреть: ";
	size_t command = 0;
	while (!(std::cin >> command) || (std::cin.peek() != '\n') || (command == 0) || !(command < users_.size() + 1))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Вы ввели неверный номер комманды. Пожалуйста, повторите ввод: " << std::endl;
	}
	std::cout << "Логин: " << users_[--command].login_ << std::endl;
	std::cout << "Имя: " << users_[command].name_ << std::endl;
	if (users_[command].online_ == true) { std::cout << "В сети: да" << std::endl; }
	else { std::cout << "В сети: нет" << std::endl; }
	std::cout << std::endl;
	system("pause");
}

void CommandModule::AnswerChatBot()
{
	size_t answer = rand() % 9;
	std::string text;
	switch (answer)
	{
	case 0:
		text = "Здесь кто-то есть?";
		break;
	case 1:
		text = "Совершенно верно! Мои мысли ушли в том же направлении!";
		break;
	case 2:
		text = "В этом и заключался мой коварный замысел!";
		break;
	case 3:
		text = "А в это время в Африке дети голодают!";
		break; 
	case 4:
		text = "А у меня есть котик! Неправда ли чудесное животное?";
		break; 
	case 5:
		text = "Ну и кто Вы после этого?";
		break; 
	case 6:
		text = "А я - Великий и Ужасный ChatBot этого Неработающего чата!";
		break; 
	case 7:
		text = "Я Вас не понимаю!";
		break; 
	case 8:
		text = "Я не говорю по-русски!";
		break; 
	}
	message_ = new Message{ message_->TimeStamp(), users_[0].login_, users_[currentUser_].login_, text };
	users_[currentUser_].history_.push_back(message_->MessageConstructor());
	users_[0].history_.push_back(message_->MessageConstructor());
	delete message_;
}
