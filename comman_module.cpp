#include "command_module.h"

//�����������/����������

CommandModule::CommandModule() {}
CommandModule::~CommandModule() {}

//���� �����. ������������ ���� ������ �������, ���� ����������� �������� ��
//�����������. ���������� ����� � ���, ������������������ � ����, ����� �� 
//���������. ���������� �������� true ��� main - ��������� ��������.
//��� ����� ������� ������ - ���������� false � ���� � main �����������
//� ����������� ����������� ������ ���������.

auto CommandModule::LoginMenu()->bool
{
	std::cout << std::endl;
	size_t command = NULL;
	std::cout << "��� ����������� ������ ������� ����� �������:" << std::endl;
	std::cout << "1 - ����� � ���" << std::endl;
	std::cout << "2 - ������������������ � ����:" << std::endl;
	std::cout << "3 - ����� �� ���������" << std::endl;
	while (!(std::cin >> command) || (std::cin.peek() != '\n') || !(command == 1 
		|| command == 2 || command == 3))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "�� ����� �������� ����� �������. ����������, ��������� ����: "
			<< std::endl;
	}
	switch (command)
	{
	case 1:
		users_[currentUser_].online_ = LogIn();
		worksUser_ = users_[currentUser_].online_;
		break;
	case 2:
		Registration();
		break;
	case 3:
		std::cout << std::endl << 
			"����� ����, ��� �� ��������� ������������ ���! ��� ������ �����������!"
			<< std::endl;
		worksChat_ = false;
		break;
	}
	return worksChat_;
}

//������������ ChatBot'�. ���������� ��� � ���� �� �������� online.
// �������������� ��������� ����� ����.

void CommandModule::InitChatBot()
{
	user_ = new Users<std::string, std::vector<std::string>>{ "ChatBot", "qwerty"
		, "Bot", true };
	users_.push_back(*user_);
	chatBotAnswers_ = { "����� ���-�� ����?",
		"���������� �����! ��� ����� ���� � ��� �� �����������!",
		"� ���� � ���������� ��� �������� �������!",
		"� � ��� ����� � ������ ���� ��������!",
		"� � ���� ���� �����! �������� �� �������� ��������?",
		"�� � ��� �� ����� �����?",
		"� � - ������� � ������� ChatBot ����� ������������� ����!",
		"� ��� �� �������!",
		"� �� ������ ��-������!" };
	delete user_;
}

//������������ ������ ������������. ���� ������: �����, ������ � ���.
//��������� ����� �� ������������ �� ���� ������������������ �������������.
//����� "exit" ��������� �� ��������� �������� ������, �.�. ���������������
//��� ������ �� ���� ����� � ���.

void CommandModule::Registration() 
{
	std::cout << std::endl;
	user_ = new Users<std::string, std::vector<std::string>>{};
	auto unique = true;
	std::cout << "������� �����: ";
	do
	{
		std::cin >> user_->login_;
		unique = true;
		for (auto& user : users_)
		{
			if ((user_->login_ == user.login_) || (user_->login_ == "exit"))
			{
				unique = false;
				std::cout << "����� �����. ������� ������ �����: ";
			}
		}
	} while (!(unique));
	std::cout << "������� ������: ";
	std::cin >> user_->password_;
	std::cout << "������� ���� ���: ";
	std::cin >> user_->name_;
	user_->online_ = false;
	users_.push_back(*user_);
	std::cout << "����������� ������� ���������. ��� ����������� ������ ������� "
		"� ������������ ��� ��� ������ �������� �������!" << std::endl;
	delete user_;
}

//������������ ������������ �� ������ �����/������, ������� �� �������
//������������������ �������������. ������������ ����� � ���������� ����
//�� ��������� ����� "exit" �� ������, ���� ������������ ����� ������� ������.
//���������� �������� "true" ��� �������� ������� ������������ � ������� 
//����� ��������������� ������������ � ��� ��� main. ��������� �������� �������
//�������� �������, � ������� �������� ������ ������������, ������������ ���� �
// ���.

auto CommandModule::LogIn() -> bool
{
	std::cout << std::endl;
	user_ = new Users<std::string, std::vector<std::string>>{};
	std::cout << "��� ����� � ������������ ��� ������� ���� ������� ������!" 
		<< std::endl;
	auto unique = true;
	auto online = true;
	do
	{
		do
		{
			auto counter = NULL;
			std::cout << "������� �����: ";
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
					std::cout << "����� �� ���������������. ��������� ���� ��� ������� "
						"exit ��� �������� � ���������� ����." << std::endl;
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
			std::cout << "������� ������: ";
			std::cin >> user_->password_;
			if (user_->password_ != users_[currentUser_].password_)
			{
				std::cout << "������ ��������. ��������� ���� ������ � ������!" 
					<< std::endl;
				unique = true;
			}
		}
	} while (unique);
	delete user_;
	return online;
}

//���� ����. ������������ ���� ������ �������, ���� ����������� �������� ��
//�����������. ���������� �������� ��������� ���� �������������, ���������� 
//������������ (������ ���������), ����������� ������� ���������� 
//������������, ���� ����� �� ��������. ���������� �������� true ��� main -
//������������ �����������, �������� ��������� ����.
//��� ����� ������� ������ - ���������� false � ��������� ���� � main 
//����������� � ����������� ��������� � ���� �����.

auto CommandModule::ChatMenu() -> bool
{
	size_t command = NULL;
	std::cout << "�������� ��������:" << std::endl;
	std::cout << "1 - �������� ��������� ����" << std::endl;
	std::cout << "2 - �������� ���������� ������������:" << std::endl;
	std::cout << "3 - ����������� ������� ���������� ������������" << std::endl;
	std::cout << "4 - ����� �� ����" << std::endl;
	while (!(std::cin >> command) || (std::cin.peek() != '\n') || !(command == 1
		|| command == 2 || command == 3 || command == 4))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "�� ����� �������� ����� ��������. ����������, ��������� ����: "
			<< std::endl;
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
		std::cout << "�� ����� �� ����!" << std::endl;
		worksUser_ = false;
		users_[currentUser_].online_ = worksUser_;
		break;
	}
	return worksUser_;
}

//������� ���������� ��������� ����. ��������� ����������� � ���� 
//������������������ �������������. ��������� ����� ChatBot � ��������� �� 
//����.

void CommandModule::MessageToAll()
{
	std::cout << "[" << users_[currentUser_].login_ << "]" << " -> "<<"[All] : ";
	std::string text;
	std::cin.ignore();
	std::getline(std::cin, text);
	message_ = new Message{ message_->TimeStamp(), users_[currentUser_].login_, 
		"All", text };
	for (auto& user : users_) 
	{ 
		user.history_.push_back(message_->MessageConstructor()); 
	}
	delete message_;
	AnswerChatBot();
}

//������� ��� ������� ��������� ��� �������� ������������.

void CommandModule::PrintHistory()
{
	system("cls");
	for (auto& user : users_[currentUser_].history_) 
	{ 
		std::cout << user << std::endl; 
	};
}

//���������� ��������� ���������� ������������. ����� ������ ������� ����������
//������� ����������, ����� ������ ������ ���� ������������������ 
//�������������, ����� ����� ������ ������������. ����������� ��������� �����,
//����������� ��������� � ��������������� �������� �������. ��������� �������
//��� �������� ������������ � ��� ����������. ��������� ������������ �� �����
//����� ���������. ChatBot ����� ��������� � ��������� �� ����, ������ ����
//�������� �����������. ����� ��������� ������ ��������� ������ ����, ��� ����
//������� ����������� ������ ��� �������� ������������.

void CommandModule::MessageToUser()
{
	PrintUsers();
	std::cout << 
		"������� ����� ������������, �������� �� ������ ��������� ���������: ";
	size_t command = 0;
	while (!(std::cin >> command) || (std::cin.peek() != '\n') || (command == 0) 
		|| !(command < users_.size() + 1))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "�� ����� �������� ����� ��������. ����������, ��������� ����: "
			<< std::endl;
	}
	std::cout << "[" << users_[currentUser_].login_ << "]" << " -> " << "[" << 
		users_[--command].login_ << "]" << " : ";
	std::string text;
	std::cin.ignore();
	std::getline(std::cin, text);
	message_ = new Message{ message_->TimeStamp(), users_[currentUser_].login_, 
		users_[command].login_, text};
	users_[currentUser_].history_.push_back(message_->MessageConstructor());
	if (command != currentUser_) 
	{ 
		users_[command].history_.push_back(message_->MessageConstructor()); 
	}
	delete message_;
	if (users_[command].login_ == "ChatBot") { AnswerChatBot(); }
}

//������� �� ����� ���� ������������������ ������������� � ����������� 
//����������� ������.

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

//���������� ����������� ������� ���������� ������������ ����� ����� 
//����������� ������������ �� ����������� ������. ����������� ��������� �����,
//����������� ��������� � ��������������� �������� �������. ������� �����, ��� 
//� ������� ������� ������ ������������.

void CommandModule::UserInfo()
{
	PrintUsers();
	std::cout << 
		"������� ����� ������������, ������� �������� �� ������ ����������: ";
	size_t command = 0;
	while (!(std::cin >> command) || (std::cin.peek() != '\n') || (command == 0) 
		|| !(command < users_.size() + 1))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "�� ����� �������� ����� ��������. ����������, ��������� ����: "
			<< std::endl;
	}
	std::cout << "�����: " << &users_[--command].login_ << std::endl;
	std::cout << "���: " << &users_[command].name_ << std::endl;
	if (users_[command].online_ == true) 
	{ 
		std::cout << "� ����: ��" << std::endl; 
	}
	else { std::cout << "� ����: ���" << std::endl; }
	std::cout << std::endl;
	system("pause");
}

//��������� ������� ChatBot'� �� ��������� ����� ���������. ChatBot ��������
//�� ����� ����� ��������� � ���� ��� ��������� ������ ���������� �����������.
//����� ��������� - ���������, �� ������ ���� ������� ������� ChatBot'�.
//�������� ��������� ����������, �� ������ ��������� ���������� ���� � �������
//��� ��������� ��������� ��������� �����. �������� ��������������, ����� 
//���������� ����������, �������� 
//size_t answer = rand() % chatBotAnswers_.size();
//� ������ ������ - ������������ ������� ������ � ������������.
//����� ChatBot'� ����������� � ���������� � �����������.

void CommandModule::AnswerChatBot()
{
	size_t answer = rand() % 9;
	std::string text;
	
	try
	{
		if (answer >= chatBotAnswers_.size()) { throw bad_range(); }
		else { text = chatBotAnswers_[answer]; }
	}
	catch (bad_range& bR) 
	{ 
		std::cout << bR.what() << std::endl; 
		system("pause");
	}
	message_ = new Message{ message_->TimeStamp(), users_[0].login_, 
		users_[currentUser_].login_, text };
	users_[currentUser_].history_.push_back(message_->MessageConstructor());
	users_[0].history_.push_back(message_->MessageConstructor());
	delete message_;
}
