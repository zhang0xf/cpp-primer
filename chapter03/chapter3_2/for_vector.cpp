#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    // 列表初始化
    vector<int> v = {1,
                     2,
                     3,
                     4,
                     5,
                     6,
                     7,
                     8,
                     9};

    for (auto &r : v) // 注:r是引用
    {
        r *= r; // r = r^2
    }

    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    // vector<int>::size_type ---> yes
    // vector::size_type      ---> no

    return 0;
}