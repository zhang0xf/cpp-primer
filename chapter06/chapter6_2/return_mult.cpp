#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

string::size_type find_char(const string &s, char ch, string::size_type &occurs)
{
    auto ret = s.size(); // 第一次出现的位置(如果有的话)
    occurs = 0;
    for (decltype(ret) i = 0; i != s.size(); ++i)
    {
        if (s[i] == ch)
        {
            if (ret == s.size()) // 只改变一次值
            {
                ret = i; // 记录ch第一次出现的位置
            }
            ++occurs; // 累加出现的次数
        }
    }

    return 0;
}

int main()
{
    string s("hello world!");
    string::size_type ctr;
    auto index = find_char(s, 'o', ctr);

    cout << "'o' occurs " << ctr << "times " << endl;
    cout << "'o' first occurs at index : " << index << endl;

    return 0;
}