#include "CommandModule.h"

CommandModule::~CommandModule() {}

auto CommandModule::LoginMenu()->size_t
{
	std::cout << std::endl;
	size_t _commandNumber = NULL;
	std::cout << "��� ����������� ������ ������� ����� ��������:" << std::endl;
	std::cout << "1 - ����� � ���" << std::endl;
	std::cout << "2 - ������������������ � ����:" << std::endl;
	std::cout << "3 - ����� �� ����" << std::endl;
	while (!(std::cin >> _commandNumber) || (std::cin.peek() != '\n') || !(_commandNumber == 1 || _commandNumber == 2 || _commandNumber == 3))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "�� ����� �������� ����� ��������. ����������, ��������� ����: " << std::endl;
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
		std::cout << std::endl << "����� ����, ��� �� ��������� ������������ ���! ��� ������ �����������!" << std::endl;
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
	std::cout << "������� �����: ";
	do
	{
		std::cin >> _user->_login;
		_unique = true;
		for (auto& user : _users)
		{
			if (_user->_login == user._login)
			{
				_unique = false;
				std::cout << "����� �����. ������� ������ �����: ";
			}
		}
	} while (!(_unique));
	std::cout << "������� ������: ";
	std::cin >> _user->password_;
	std::cout << "������� ���� ���: ";
	std::cin >> _user->_name;
	_user->_online = false;
	_users.push_back(*_user);
	std::cout << "����������� ������� ���������. ��� ����������� ������ ������� � ������������ ��� ��� ������ �������� �������!" << std::endl;
	delete _user;
}

auto CommandModule::LogIn() -> bool
{
	std::cout << std::endl;
	_user = new Users{};
	std::cout << "��� ����� � ������������ ��� ������� ���� ������� ������!" << std::endl;
	auto _unique = true;
	do
	{
		do
		{
			auto _counter = NULL;
			std::cout << "������� �����: ";
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
					std::cout << "����� �� ���������������. ��������� ���� ��� ������� exit ��� �������� � ���������� ����." << std::endl;
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
			std::cout << "������� ������: ";
			std::cin >> _user->password_;
			if (_user->password_ != _users[_currentUser].password_)
			{
				std::cout << "������ ��������. ��������� ���� ������ � ������!" << std::endl;
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
	std::cout << "�������� ��������:" << std::endl;
	std::cout << "1 - �������� ��������� ����" << std::endl;
	std::cout << "2 - �������� ���������� ������������:" << std::endl;
	std::cout << "3 - ����������� ������� ���������� ������������" << std::endl;
	std::cout << "4 - ����� �� ����" << std::endl;
	while (!(std::cin >> _command) || (std::cin.peek() != '\n') || !(_command == 1 || _command == 2 || _command == 3 || _command == 4))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "�� ����� �������� ����� ��������. ����������, ��������� ����: " << std::endl;
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
		std::cout << "�� ����� �� ����!" << std::endl;
		break;
	}
	return _command;
}
