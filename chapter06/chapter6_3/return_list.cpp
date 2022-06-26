#include <iostream>
#include <string>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::vector;

vector<string> process()
{
    string expected("zhangfei");
    string actual("hello world");

    if (expected.empty())
    {
        return {}; // 空列表
    }
    else if (expected != actual)
    {
        return {"functionX", expected, actual}; // 使用{}包围值的列表
    }
    else
    {
        return {"functionX", "Okey"};
    }
}

int main()
{
    process();
    return 0;
}