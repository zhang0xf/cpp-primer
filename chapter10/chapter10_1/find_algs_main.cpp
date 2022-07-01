#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int main()
{
    vector<int> vec;
    int val = 42;

    // 成功返回指定值的迭代器
    // 失败返回第二个参数,即vec.cend()
    auto result = std::find(vec.cbegin(), vec.cend(), val);

    std::cout << "The value " << val
              << (result == vec.cend() ? " is not present " : " is present ") << std::endl;

    return 0;
}