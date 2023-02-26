#include "CommandModule.h"

CommandModule::~CommandModule() {}

auto CommandModule::LoginMenu()->size_t
{
	std::cout << std::endl;
	size_t _commandNumber = NULL;
	std::cout << "Для продолжения работы введите номер комманды:" << std::endl;
	std::cout << "1 - войти в чат" << std::endl;
	std::cout << "2 - зарегистрироваться в чате:" << std::endl;
	std::cout << "3 - выйти из чата" << std::endl;
	while (!(std::cin >> _commandNumber) || (std::cin.peek() != '\n') || !(_commandNumber == 1 || _commandNumber == 2 || _commandNumber == 3))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Вы ввели неверный номер комманды. Пожалуйста, повторите ввод: " << std::endl;
	}
	switch (_commandNumber)
	{
	case 1:
		_users[_currentUser]._online = LogIn();
		break;
	case 2:
		Registration();
		break;
	case 3:
		std::cout << std::endl << "Очень жаль, что Вы покидаете Неработающий Чат! Ждём Вашего возвращения!" << std::endl;
		break;
	}
	return _commandNumber;
}

void CommandModule::InitChatBot()
{
	_user = new Users{ "ChatBot", "qwerty", "Bot", false, nullptr };
	_users.push_back(*_user);
	delete _user;
}

void CommandModule::Registration() 
{
	std::cout << std::endl;
	_user = new Users{};
	auto _unique = true;
	std::cout << "Введите логин: ";
	do
	{
		std::cin >> _user->_login;
		_unique = true;
		for (auto& user : _users)
		{
			if (_user->_login == user._login)
			{
				_unique = false;
				std::cout << "Логин занят. Введите другой логин: ";
			}
		}
	} while (!(_unique));
	std::cout << "Введите пароль: ";
	std::cin >> _user->password_;
	std::cout << "Введите Ваше имя: ";
	std::cin >> _user->_name;
	_user->_online = false;
	_users.push_back(*_user);
	std::cout << "Регистрация успешно завершена. Для продолжения работы войдите в Неработающий Чат под Вашими учетными данными!" << std::endl;
	delete _user;
}

auto CommandModule::LogIn() -> bool
{
	std::cout << std::endl;
	_user = new Users{};
	std::cout << "Для входа в Неработающий Чат введите Ваши учетные данные!" << std::endl;
	auto _unique = true;
	do
	{
		do
		{
			auto _counter = NULL;
			std::cout << "Введите логин: ";
			std::cin >> _user->_login;
			for (auto& user : _users)
			{
				if (_user->_login == user._login)
				{
					_unique = false;
					_currentUser = _counter;
				}
				if (_unique && (_counter == _users.size() - 1)) 
				{ 
					std::cout << "Логин не зарегистрирован. Повторите ввод или введите exit для возврата в предыдущее меню." << std::endl;
				}
				if (_user->_login == "exit") 
				{
					_unique = false;
				}
				_counter++;
			}
		} while (_unique);
		if (_user->_login != "exit")
		{
			std::cout << "Введите пароль: ";
			std::cin >> _user->password_;
			if (_user->password_ != _users[_currentUser].password_)
			{
				std::cout << "Пароль неверный. Повторите ввод логина и пароля!" << std::endl;
				_unique = true;
			}
		}
	} while (_unique);
	delete _user;
	return true;
}

auto CommandModule::ChatMenu() -> size_t
{
	std::cout << std::endl;
	size_t _command = NULL;
	std::cout << "Выберите действие:" << std::endl;
	std::cout << "1 - написать сообщение всем" << std::endl;
	std::cout << "2 - написать выбранному пользователю:" << std::endl;
	std::cout << "3 - просмотреть профиль выбранного пользователя" << std::endl;
	std::cout << "4 - выйти из чата" << std::endl;
	while (!(std::cin >> _command) || (std::cin.peek() != '\n') || !(_command == 1 || _command == 2 || _command == 3 || _command == 4))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Вы ввели неверный номер комманды. Пожалуйста, повторите ввод: " << std::endl;
	}
	switch (_command)
	{
	case 1:
		
		break;
	case 2:
		
		break;
	case 3:
		
		break;
	case 4:
		std::cout << "Вы вышли из чата!" << std::endl;
		break;
	}
	return _command;
}
