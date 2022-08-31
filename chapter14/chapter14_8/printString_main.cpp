#include <algorithm>
#include <vector>
#include "printString.h"

// 如果定义了函数调用运算符，则该类的对象称为函数对象

int main() {
    PrintString printer;

    printer("zhangfei");

    PrintString errors(std::cerr, '\n');

    errors("some fucking thing happened");

    // 函数对象,常常用于泛型算法
    std::vector<std::string> svec;
    svec = {"zhangfei", "hello world", "test"};
    std::for_each(svec.begin(), svec.end(), PrintString(std::cout, '\n'));

    return 0;
}