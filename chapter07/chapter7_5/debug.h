#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>

// 啥意思???没弄懂!!!
// 字面值常量类:数据成员都是字面值类型的聚合类
class Deubg
{
public:
    constexpr Deubg(bool b = true) : hw(b), io(b), other(b) {}
    constexpr Deubg(bool h, bool i, bool o) : hw(h), io(i), other(o) {}

    constexpr bool any() { return hw || io || other; }

    void set_hw(bool b) { hw = b; }
    void set_io(bool b) { io = b; }
    void set_other(bool b) { other = b; }

private:
    bool hw;
    bool io;
    bool other;
};

#endif