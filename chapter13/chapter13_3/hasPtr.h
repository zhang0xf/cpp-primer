#ifndef HASPTR_H
#define HASPTR_H

#include <string>
#include <memory>

class HasPtr;

void swap(HasPtr &, HasPtr &);

class HasPtr
{
    friend void swap(HasPtr &, HasPtr &);

public:
    HasPtr(const std::string &s = std::string()) : p(new std::string(s)), i(0) {}
    HasPtr(const HasPtr &po) : p(new std::string(*po.p)), i(po.i) {}
    HasPtr &operator=(const HasPtr &); // 拷贝赋值
    HasPtr &operator=(HasPtr);         // 拷贝交换(对拷贝复制操作的另一种实现)
    ~HasPtr() { delete p; }

    void print();

private:
    std::string *p;
    int i;
};

// 编写自定义的swap函数
inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.p, rhs.p); // 只交换指针,避免string的多次拷贝
    swap(lhs.i, rhs.i);
}

#endif
