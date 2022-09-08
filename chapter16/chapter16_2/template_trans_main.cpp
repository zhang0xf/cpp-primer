#include <fstream>
#include "template_trans.h"

int main() {
    long lng = 0;
    flexibleCompare(1024, lng); // 正确:调用flexibleCompare(long, int)

    print(std::cout, 42);
    std::ofstream fout("./data/output.txt");
    print(fout, 42); // 正确:使用print(std::ostream&, int);将fout转化为ostream&

    // T1是显示指定的, T2和T3是从函数实参类型推断而来的
    auto val3 = sum<long long>(1, lng); // long long sum(int, long)
    // auto val4 = alternative_sum<long long>(1, lng); // error
    auto val5 = alternative_sum<long long, int, long>(1, lng);

    std::cout << val3;
    std::cout << val5;

    // func(compare); // error : 不能从函数指针类型确定模版实参
    func(compare2<int>); // 显示模版实参,以消除歧义

    int i = 0;
    const int ci = 0;
    // 对f1的调用使用实参所引用的类型作为模版参数类型
    f1(i);  // T = int
    f1(ci); // T = const int
    // f1(6); // error: 传递给一个&的参数,必须是一个左值

    f2(i);
    f2(ci); // ci是const int, 但是模版参数T是int
    f2(7);  // const &可以绑定到一个右值 T = int

    f3(42); // T = int
    f3(i);  // 引用折叠??? T = int&
    f3(ci); // T = const int&

    return 0;
}