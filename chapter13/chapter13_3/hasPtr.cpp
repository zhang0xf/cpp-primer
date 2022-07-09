#include <iostream>
#include "./hasPtr.h"

void HasPtr::print()
{
    std::cout << "string is " << *(this->p) << std::endl;
}

// 拷贝交换
HasPtr &HasPtr::operator=(HasPtr hp) // 右侧对象的副本,非引用
{
    // 发生异常时是安全的
    // 代码中唯一可能抛出异常的是拷贝构造函数中的new表达式。如果真发生了异常，它也会在我们改变左侧运算对象之前发生。
    swap(*this, hp); // 交换左侧对象和局部变脸
    return *this;
    // 局部变量销毁,即销毁了本对象
}
