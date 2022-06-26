#include <iostream>

using std::cin;
using std::cout;
using std::endl;

size_t count_calls()
{
    /* static: 在程序的执行路径第一次经过对象定义语句时初始化，并且直到程序终止才被销毁，
    在此期间即使对象所在的函数结束执行也不会对它有影响。*/
    static size_t ctr = 0;
    return ++ctr;
}

int main()
{
    for (size_t i = 0; i != 10; ++i)
    {
        cout << count_calls() << endl;
    }

    return 0;
}