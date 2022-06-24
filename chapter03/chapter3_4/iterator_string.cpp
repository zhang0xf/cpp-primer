#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string s("hello world!!!");

    if (s.begin() != s.end()) // s非空
    {
        auto it = s.begin();
        *it = toupper(*it); // 第一个字符改为大写
    }

    cout << s << endl;

    return 0;
}