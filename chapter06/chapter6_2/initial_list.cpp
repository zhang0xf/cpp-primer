#include <initializer_list>
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::initializer_list;
using std::ostream;
using std::string;

class ErrCode
{
public:
    ErrCode() {}
    ErrCode(int) {}

public:
    string msg() { return ""; }
};

// 可变形参,但类型相同:本例中为string.
void error_msg(initializer_list<string> il)
{
    for (auto beg = il.begin(); beg != il.end(); ++beg)
    {
        cout << *beg << " ";
    }
    cout << endl;
}

// 重载
void error_msg(ErrCode e, initializer_list<string> il)
{
    cout << e.msg() << " ";
    for (const auto &elem : il) // 范围for
    {
        cout << elem << " ";
    }
    cout << endl;
}

int main()
{
    string expected("zhangfei");
    string actual("hello world");

    if (expected != actual)
    {
        error_msg({"functionX", expected, actual}); // 使用{}传递值序列
    }
    else
    {
        error_msg({"functionX", "Okey"});
    }

    if (expected != actual)
    {
        error_msg(ErrCode(42), {"functionX", expected, actual}); // 含有initializer_list形参的函数也可以同时拥有其他形参
    }
    else
    {
        error_msg(ErrCode(0), {"functionX", "Okey"});
    }

    return 0;
}