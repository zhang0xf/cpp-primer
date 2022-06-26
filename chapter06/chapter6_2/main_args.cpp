#include <iostream>

using std::cout;
using std::endl;

// 第二个形参argv是一个数组，它的元素是指向C风格字符串的指针；
// 第一个形参argc表示数组中字符串的数量。
// argv[0]:保存函数名字
int main(int argc, char *argv[])
{
    // use argv[1],argv[2] ...
    cout << argc << *argv << endl;
    return 0;
}