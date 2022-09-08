#ifndef TEMPLATE_TRANS_H
#define TEMPLATE_TRANS_H

#include <iostream>

// 实参类型可以不同,但必须兼容
template <typename A, typename B>
int flexibleCompare(const A &v1, const B &v2) {
    if (v1 < v2) {
        return -1;
    }
    if (v2 > v1) {
        return 1;
    }
    return 0;
}

// 普通函数实参
template <typename T>
std::ostream &print(std::ostream &os, const T &obj) {
    return os << obj;
}

// 没有任何函数实参可以推断T1返回值的类型
// 调用者必须提供一个返回类型
template <typename T1, typename T2, typename T3>
T1 sum(T2, T3) {
    return T1();
}

// 只有尾部的显示模版实参才可以忽略,而且前提是可以从函数实参推断出来
// 糟糕的设计: 用户必须指定所有三个模版的参数
template <typename T1, typename T2, typename T3>
T3 alternative_sum(T2, T1) {
    return T3();
}

// 避免用户提供返回类型的负担
// 尾置返回允许我们在参数列表之后声明返回类型
template <typename It>
auto fcn(It begin, It end) -> decltype(*begin) {
    // 处理序列
    // ...
    std::cout << *end << std::endl;
    return *begin; // 返回序列中一个元素的引用
}

// 返回元素值的拷贝,而非类型引用
// decltype(*begin)返回元素类型的引用
// remove_reference::type脱去引用,剩下元素类型本省
template <typename It>
auto fcn2(It begin, It end) -> typename std::remove_reference<decltype(*begin)>::type {
    // 处理序列
    // ...
    std::cout << *end << std::endl;
    return *begin; // 返回序列中一个元素的拷贝
}

// 函数指针
template <typename T>
int compare2(const T &, const T &) {
    // TODO
    return 0;
}

// pf1指向实例int compare(const int &, const int &);
int (*pf1)(const int &, const int &) = compare2;

// 重载func接受不同的函数指针类型
void func(int (*)(const std::string &, const std::string &)) {
    // TODO
}

void func(int (*)(const int &, const int &)) {
    // TODO
}

// 从左值引用函数参数推断
template <typename T>
void f1(T &) {
    // TODO
}

template <typename T>
void f2(const T &) {
    // TODO
}

// 从右值引用函数参数推断
template <typename T>
void f3(T &&) {
    // TODO
}

// 转发
// 接受一个可调用对象和另外两个参数的模版
// flip1是一个不完整的实现: 顶层const和引用被丢弃 // TO BE BETTER
template <typename F, typename T1, typename T2>
void flip1(F f, T1 t1, T2 t2) {
    f(t1, t2);
}

// 定义能够保持类型信息的函数参数
// TO BE BETTER
template <typename F, typename T1, typename T2>
void flip2(F f, T1 &&t1, T2 &&t2) {
    f(t2, t1);
}

// 在调用中使用std::forward保持类型信息
template <typename F, typename T1, typename T2>
void flip3(F f, T1 &&t1, T2 &&t2) {
    f(std::forward<T2>(t2), std::forward<T1>(t1));
}

#endif