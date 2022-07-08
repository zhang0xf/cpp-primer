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
