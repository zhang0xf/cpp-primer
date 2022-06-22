#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main()
{
    string s("hello world!!!");

    // decltype推断表达式类型（string::size_type）
    decltype(s.size()) punct_cnt = 0;

    // 统计s中的标点符号的数量
    for (auto c : s) // auto自动推到类型
    {
        if (ispunct(c)) // 继承于c标准头文件:ctype.h
        {
            ++punct_cnt;
        }
    }

    cout << punct_cnt << " punctuation charactors in " << s << std::endl;

    return 0;
}