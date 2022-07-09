#ifndef FLODER_H
#define FLODER_H

#include <set>

#include "./message.h"

class Floder
{
public:
    void addMsg(Message *);
    void removeMsg(Message *);
    ~Floder();

private:
    std::set<Message *> messages;
    // 公用工具函数
    void remove_from_message();
};

#endif