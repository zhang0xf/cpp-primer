#include <iterator>
#include <list>
#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

// iostream_iterator将流当作元素序列来处理

int main()
{
    vector<int> vec;
    std::istream_iterator<int> int_it(std::cin); // 从cin读取int(迭代器int_it绑定到cin)
    std::istream_iterator<int> int_eof;          // 默认初始化 = 创建了一个尾后迭代器

    while (int_it != int_eof) // 当有数据可读时
    {
        vec.push_back(*int_it++); // 后置++,返回旧值
    }

    // 或者从迭代器范围构造vec
    vector<int> vec2(int_it, int_eof);

    return 0;
}