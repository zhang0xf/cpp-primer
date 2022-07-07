#include "memory"

int main()
{
    int *p = new int[42]();                              // 分配数组(值初始化)
    int *p1 = new int[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // 列表初始化
    delete[] p;                                          // 销毁数组
    delete[] p1;

    // 智能指针和数组
    std::unique_ptr<int[]> up(new int[10]);

    for (size_t i = 0; i != 10; i++)
    {
        up[i] = i; // 为每个元素赋值
    }

    up.release(); // 自动用 delete[] 销毁其指针

    // 使用shared_ptr必须提供一个删除器(使用lambda)
    std::shared_ptr<int> sp(new int[10], [](int *p)
                            { delete[] p; });

    // shared_ptr未定义下标运算,并且不支持指针的算术运算.
    for (size_t i = 0; i != 10; i++)
    {
        *(sp.get() + i) = i; // 为每个元素赋值
    }

    sp.reset();

    return 0;
}