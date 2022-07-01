#include <iterator> // back_inserter
#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;

// 插入迭代器:向容器中写入值

int main()
{
    vector<int> vec;

    auto it = std::back_inserter(vec); // 通过迭代器赋值,会将元素添加到容器中

    *it = 42; // size = 1

    *it = 45; // size = 2

    // fill_n泛型算法(算法本身不会修改容器:插入、删除)
    std::fill_n(std::back_inserter(vec), 10, 0); // 插入迭代器,添加10个元素到容器

    // print
    for (const auto &it : vec)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    return 0;
}