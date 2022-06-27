#include <string>

using std::string;

// using类型别名(相当于typedef)
using F = int(int *, int);      // F:函数类型
using PF = int (*)(int *, int); // PF:函数指针类型

// 函数返回函数指针类型
PF func1(int);
F *func1(int);                       // 等价申明
int (*f1(int))(int *, int);          // 复杂的等价申明
auto f1(int) -> int (*)(int *, int); // 使用"尾置返回类型"的等价申明

// 将auto和decltype用于函数指针类型
string::size_type sumLength(const string &, const string &);
string::size_type largeLength(const string &, const string &);

decltype(sumLength) *getFcn(const string &); // 注意*号:decltype返回函数类型,而非函数指针类型,故需要显示加上*号以表示函数指针类型

int main()
{
    return 0;
}