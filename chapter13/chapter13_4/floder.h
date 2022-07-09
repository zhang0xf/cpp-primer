#ifndef FLODER_H
#define FLODER_H

#include <set>

#include "./message.h"

// Floder类未完成,目前仅根据message做出反应,没有主动操作message的动作

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