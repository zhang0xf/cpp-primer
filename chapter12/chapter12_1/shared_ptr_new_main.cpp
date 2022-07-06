#include <memory>

std::shared_ptr<int> clone(int p)
{
    return std::shared_ptr<int>(new int(p));
}

void process(std::shared_ptr<int> ptr)
{
    ptr = nullptr; // 使用ptr
} // ptr离开作用域,被销毁

int main()
{
    auto p0 = new int(42);
    delete p0;
    std::shared_ptr<int> p1(new int(42));
    auto p3 = clone(42);

    process(p1); // 引用计数+1
    *p1 = 51;    // 合法

    int *x(new int(1024));
    process(std::shared_ptr<int>(x)); // process结束内存会被释放
    *x = 51;                          // 非法

    return 0;
}