#include <iostream>
#include <string>

using std::cin;
using std::string;

int main()
{
    string buf;

    while (cin >> buf && !buf.empty())
    {
        switch (buf[0])
        {
        case '-':
            for (auto it = buf.begin(); it != buf.end(); ++it)
            {
                if (*it == ' ')
                    break; // #1,离开for循环
            }
            break; // #2,离开switch语句
        default:
            break;
        }
    } // 结束while循环

    return 0;
}