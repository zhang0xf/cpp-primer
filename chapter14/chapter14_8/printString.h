#ifndef PRINT_STRING_H
#define PRINT_STRING_H

#include <iostream>
#include <string>

class PrintString {
public:
    PrintString(std::ostream &o = std::cout, char c = ' ') :
        os(o), sep(c) {
    }

    // 重载函数调用运算符
    void operator()(const std::string &s) const;

private:
    std::ostream &os; // 用于写入的目的流
    char sep;         // 用于将不同输出隔开的字符
};

#endif