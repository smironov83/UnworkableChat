#include "message.h"

//����������� ��������� ���������: ������� ��������� �����, ����� �����������,
//������������� ����������, ����� ���������

Message::Message(std::string const timeStamp, std::string const from,
  std::string const to, std::string const text) : timeStamp_(timeStamp), 
  from_(from), to_(to), text_(text) {}

//����������

Message::~Message() {}

//�������� ������� ��������� �����, ��������������� � �������� �������� 
// ������������ ��� � ���������� ���������� �������� � ������� string

auto Message::TimeStamp() -> std::string const
{
    const size_t range = 26;
    time_t timeLong = NULL;
    char timebuf[range]{};
    time(&timeLong);
    ctime_s(timebuf, range, &timeLong);
    std::string timeNow = "[";
    for (auto& user : timebuf) { timeNow.push_back(user); }
    timeNow.resize(25);
    timeNow.push_back(']');
	return timeNow;
}

//���������� � ��������������� ������� ���������� � ���������� ������ �������.


auto Message::MessageConstructor() -> std::string const
{
    std::string const message = timeStamp_ + " " + from_ + " to " + to_ + 
      " : " + text_;
    return message;
}
