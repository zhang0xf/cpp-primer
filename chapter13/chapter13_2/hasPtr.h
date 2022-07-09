#ifndef HASPTR_H
#define HASPTR_H

#include <string>
#include <memory>

// 拷贝控制和资源管理

// 行为类似"值"
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

// 行为类似"指针"
class HasPtr2
{
public:
    HasPtr2(const std::string &s = std::string()) : p(new std::string(s)), i(0), use(new std::size_t(1)) {} // 构造函数
    HasPtr2(const HasPtr2 &po) : p(po.p), i(po.i), use(po.use) { ++*use; }                                  // 拷贝构造(递增计数器)
    HasPtr2 &operator=(const HasPtr2 &);                                                                    // 拷贝赋值操作
    ~HasPtr2();                                                                                             // 析构函数

private:
    std::string *p;
    int i;
    std::size_t *use; // 引用计数
};

#endif