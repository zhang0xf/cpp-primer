#ifndef TEMPLATE_MATCH_H
#define TEMPLATE_MATCH_H

#include <string>
#include <sstream>

// 打印任何我们不能处理的类型和
template <typename T>
std::string debug_rep(const T &t) {
    std::ostringstream ret;
    ret << t; // 使用T的输出运算符打印t的一个表示形式
    return ret.str();
}

// 打印指针的值,后面跟指针指向的对象
// 注意: 此函数不能用于char*,因为IO库为char*定义了一个<<版本
template <typename T>
std::string debug_rep(T *p) {
    std::ostringstream ret;

    ret << "pointer: " << p; // 打印指针本身的值
    if (p) {
        ret << " " << debug_rep(*p); // 打印p指向的值
    } else {
        ret << "null pointer"; // 或指出p为空
    }

    return ret.str(); // 返回ret绑定的string的一个副本
}

// 普通非模版的函数(优先匹配)
std::string debug_rep(const std::string &s) {
    return '"' + s + '"';
}

// 将字符指针转换为string,并调用string版本的debug_rep
std::string debug_rep(char *p) {
    return debug_rep(std::string(p));
}

std::string debug_rep(const char *p) {
    return debug_rep(std::string(p));
}

#endif