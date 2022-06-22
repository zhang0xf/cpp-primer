#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// 将0~15之间的10进制数转换为16进制数
// ctrl+d结束输入

int main()
{
    const string hexdigits = "0123456789ABCDEF"; // string常量:可能的16进制数

    cout << "enter a series of numbers between 0 and 15 "
         << "separated by spaces. Hit ENTER when finished."
         << endl;

    string result;
    string::size_type n;

    while (cin >> n)
    {
        if (n < hexdigits.size())
        {
            result += hexdigits[n]; // 得到对应的16进制数字
        }
    }

    cout << "your hex number is : " << result << endl;

    return 0;
}