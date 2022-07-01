#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

using std::list;
using std::vector;

int main()
{
    // find操作的对象是表示元素范围的迭代器,故可应用于多种容器!
    vector<int> vec;
    list<int> li;
    int ia[] = {1, 2, 42, 4, 5, 6, 7, 8};

    int val = 42;

    // 成功返回指定值的迭代器
    // 失败返回第二个参数,即vec.cend()
    auto result1 = std::find(vec.cbegin(), vec.cend(), val);
    std::cout << "The value " << val
              << (result1 == vec.cend() ? " is not present " : " is present ") << std::endl;

    auto result2 = std::find(li.cbegin(), li.cend(), val);
    std::cout << "The value " << val
              << (result2 == li.cend() ? " is not present " : " is present ") << std::endl;

    auto result3 = std::find(std::begin(ia), std::end(ia), val);
    std::cout << "The value " << val
              << (result3 == std::end(ia) ? " is not present " : " is present ") << std::endl;

    auto result4 = std::find(ia + 1, ia + 4, val);
    std::cout << "The value " << val
              << (result4 == ia + 4 ? " is not present " : " is present ") << std::endl;

    return 0;
}