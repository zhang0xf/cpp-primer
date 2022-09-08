#ifndef TEMPLATE_VARIDIAC_H
#define TEMPLATE_VARIDIAC_H

#include <iostream>
#include "../chapter16_3/template_match.h"

// 可变参数模版
// Args是一个模版参数包,rest是一个函数参数包
// Args表示0个或多个模版类型参数
// rest表示0个或多个函数参数
template <typename T, typename... Args>
void foo(const T &t, const Args &...rest) {
    std::cout << t << std::endl;
    std::cout << sizeof...(rest) << std::endl;
}

// sizeof运算符
template <typename... Args>
void g(Args... args) {
    std::cout << sizeof...(Args) << std::endl; // 类型参数的数目
    std::cout << sizeof...(args) << std::endl; // 函数参数的数目
}

// 编写可变参数函数模版
// 用来终止递归并打印最后一个元素的函数!!!!
// 此函数必须在可变参数版本的print定义之前声明
template <typename T>
std::ostream &print(std::ostream &os, const T &t) {
    return os << t; // 包中最后一个元素之后不打印分割符
}

// 包中除了最后一个元素之外的其他元素都会调用这个版本的print
template <typename T, typename... Args>
std::ostream &print(std::ostream &os, const T &t, const Args &...rest) {
    os << t << ", ";           // 打印第一个实参
    return print(os, rest...); // 递归调用,打印其他实参
}

// 包扩展
// print2中的扩展仅仅将包扩展成其构成元素
template <typename T, typename... Args>
std::ostream &print2(std::ostream &os, const T &t, const Args &...rest) { // 扩展Args
    os << t << ", ";
    return print2(os, rest...); // 扩展rest
}

// 更复杂的扩展
// 在print调用中对每个实参调用debug_rep
template <typename... Args>
std::ostream &errorMsg(std::ostream &os, const Args &...rest) {
    // print(os, debug_rep(a1), debug_rep(a2), ..., debug_rep(an));
    return print(os, debug_rep(rest)...);
    // return print(os, debug_rep(rest...)); // error 注意 ... 位置
}

// 转发参数包

#endif