#ifndef FUNCTION_TABLE_H
#define FUNCTION_TABLE_H

#include <map>
#include <string>

// 普通函数
int add(int a, int b) {
    return a + b;
}

// lambda(其产生一个未命名的函数对象类)
auto mod = [](int i, int j) { return i % j; };

// 函数对象类
struct divide {
    int operator()(int denominator, int divisor) {
        return denominator / divisor;
    }
};

// 都具有相同的调用形式int(int, int)

// 创建函数表(存储这些可调用对象的“指针”)
// 构建从运算符到函数指针的映射关系,其中函数接收2个int,返回一个int
std::map<std::string, int (*)(int, int)> binops;

#endif