#include "screen.h"

void Screen::some_member() const // 注意const成员函数
{
    ++access_ctr; // 保存一个记录值,用于记录成员函数被调用的次数
    // 该成员需要完成其他工作 ...
}
