#include "Message.h"

Message::Message() {}
Message::~Message() {}

auto Message::timeStamp() -> std::string
{
    time_t time_;
    char timebuf[26];
    time(&time_);
    ctime_s(timebuf, 26, &time_);
    std::string timeNow_;
    for (auto& user : timebuf) { timeNow_.push_back(user); }

	return timeNow_;
}
