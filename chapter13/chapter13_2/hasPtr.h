#ifndef HASPTR_H
#define HASPTR_H

#include <string>
#include <memory>

// 拷贝控制和资源管理

// 行为类似值
class HasPtr
{
public:
    HasPtr(const std::string &s = std::string()) : p(new std::string(s)), i(0) {} // 构造函数
    HasPtr(const HasPtr &po) : p(new std::string(*po.p)), i(po.i) {}              // 拷贝构造
    HasPtr &operator=(const HasPtr &);                                            // 拷贝赋值操作
    ~HasPtr() { delete p; }                                                       // 析构函数

private:
    std::string *p;
    int i;
};

#endif