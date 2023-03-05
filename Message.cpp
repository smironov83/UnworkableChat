#include "message.h"

Message::Message(std::string timeStamp, std::string from, std::string to, std::string text) :
    timeStamp_(timeStamp), from_(from), to_(to), text_(text) {}

Message::~Message() {}

auto Message::TimeStamp() -> std::string
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

auto Message::MessageConstructor() -> std::string
{
    std::string message = timeStamp_ + " " + from_ + " to " + to_ + " : " + text_;
    return message;
}
