#include <string>

using std::string;

bool lengthCompare(const string &, const string &); // 比较两个string对象的长度

// 函数指针做形参
void useBigger(const string &s1, const string &s2, bool pf(const string &, const string &));
void useBigger(const string &s1, const string &s2, bool (*pf)(const string &, const string &)); // 等价申明

// 使用类型别名简化代码
// FUNC和FUNC2是函数类型
typedef bool FUNC(const string &, const string &);
typedef decltype(lengthCompare) FUNC2; // 等价类型

// FUNC_P和FUNC2_P是函数指针类型
typedef bool (*FUNC_P)(const string &, const string &);
typedef decltype(lengthCompare) *FUNC2_P; // 等价类型

// 使用类型别名重新申明useBigger
void useBigger(const string &, const string &, FUNC);
void useBigger(const string &, const string &, FUNC_P); // 等价申明

int main()
{
    string s1("zhangfei");
    string s2("hello world");

    // useBigger(s1, s2, lengthCompare); // 由于函数没有实现,故先注释

    return 0;
}