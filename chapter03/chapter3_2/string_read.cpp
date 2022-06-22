#include <iostream>
#include <string>

using std::cin;
using std::string;

int main()
{
    string line;
    // 每次读入一整行，直至文件末尾
    while (getline(cin, line))
    {
        // 输出其中超出80个字符的行
        // string::size_type
        if (!line.empty() && line.size() >= 80)
        {
            std::cout << line << std::endl;
        }
    }

    return 0;
}