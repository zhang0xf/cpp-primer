#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main()
{
    string s("hello world!!!");

    // 依次处理s中的字符，直至处理完所有字符或者遇到空白
    for (decltype(s.size()) index = 0;
         index != s.size() && !isspace(s[index]);
         ++index)
    {
        s[index] = toupper(s[index]); // 将当前字符改为大写
    }

    cout << s << std::endl;

    return 0;
}