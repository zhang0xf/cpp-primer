#include <iterator> // back_inserter
#include <vector>
#include <iostream>
#include <algorithm>

using std::vector;

void print(vector<int> vec)
{
    for (const auto &it : vec)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
}

int main()
{
    vector<int> vec = {1, 2, 3, 4, 5, 6};
    vector<int> ivec;

    print(vec);
    print(ivec);

    // 将所有值为3的元素改为100
    std::replace(vec.begin(), vec.end(), 3, 100);

    // 不改变原序列,使用back_inserter按需增长目标序列(100使用99替换)
    std::replace_copy(vec.cbegin(), vec.cend(), std::back_inserter(ivec), 100, 99);

    print(vec);
    print(ivec);

    return 0;
}