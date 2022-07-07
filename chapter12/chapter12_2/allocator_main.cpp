#include <memory>
#include <string>
#include <iostream>

int main()
{
    int n = 10;
    std::allocator<std::string> alloc; // 可以分配string的allocator对象
    // 分配内存和构造对象分两步
    const auto p = alloc.allocate(n); // 分配n个未初始化的string(原始的,为构造的内存空间)
    alloc.construct(p, "zahngfei");   // 用来在p指向的内存中构造一个对象
    // 销毁和释放内存分两步
    alloc.destroy(p);       // 对p指向的对象执行析构函数
    alloc.deallocate(p, n); // 释放指针p中地址开始的内存,这块内存保存了n个string类型的对象

    // 示例:
    std::allocator<std::string> alloc2;
    const auto p2 = alloc.allocate(n); // 常量!!!
    auto q2 = p2;
    auto p_tmp = p2;

    // 构造对象
    alloc2.construct(q2++, "test");
    alloc2.construct(q2++, 10, 'C');
    alloc2.construct(q2++, "hello world");
    alloc2.construct(q2++, "zhangfei");

    std::cout << *p2 << std::endl;

    // 打印
    while (p_tmp != q2)
    {
        std::cout << *p_tmp << std::endl;
        ++p_tmp;
    }

    // 销毁和释放内存是分开的!
    while (q2 != p2)
    {
        alloc2.destroy(--q2); // 调用析构函数销毁销毁对象
    }

    // 释放内存
    alloc2.deallocate(p2, n);

    return 0;
}