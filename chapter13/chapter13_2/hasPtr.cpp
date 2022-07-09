#include "./hasPtr.h"

HasPtr &HasPtr::operator=(const HasPtr &rhs)
{
    // 必须能够拷贝自己,且发生异常时是安全的
    auto new_p = new std::string(*rhs.p); // 拷贝底层string
    delete this->p;                       // 释放旧内存
    p = new_p;                            // 从右侧运算对象拷贝数据
    i = rhs.i;
    return *this;
}

HasPtr2::~HasPtr2()
{
    if (--*use == 0) // 如果引用计数变为0
    {
        delete p;   // 释放string内存
        delete use; // 释放计数器内存
    }
}

HasPtr2 &HasPtr2::operator=(const HasPtr2 &rhs)
{
    // 必须能够拷贝自己,且发生异常时是安全的
    ++*rhs.use;      // 递增右侧运算对象的引用计数
    if (--*use == 0) // 递减本对象的引用计数
    {
        delete p;
        delete use;
    }

    // 拷贝数据
    p = rhs.p;
    i = rhs.i;
    use = rhs.use;

    return *this;
}