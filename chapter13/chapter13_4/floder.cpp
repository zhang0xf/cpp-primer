#include <iostream>
#include "./floder.h"

void Floder::addMsg(Message *msg)
{
    messages.insert(msg);
}

void Floder::removeMsg(Message *msg)
{
    messages.erase(msg);
}

Floder::~Floder()
{
    std::cout << "floder release" << std::endl;
    remove_from_message();
}

void Floder::remove_from_message()
{
    for (auto msg : messages)
    {
        msg->remove(*this);
    }
}