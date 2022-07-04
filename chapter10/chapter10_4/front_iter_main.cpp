#include <iterator>
#include <list>
#include <algorithm>

using std::list;

int main()
{
    list<int> li = {1,
                    2,
                    3,
                    4};

    list<int> li2, li3; // 空列表

    // 拷贝完成后,li2包含4 3 2 1
    std::copy(li.cbegin(), li.cend(), std::front_inserter(li2));

    // 拷贝完成后,li2包含1 2 3 4
    std::copy(li.cbegin(), li.cend(), std::inserter(li3, li3.begin())); // inserter返回指向原来的元素

    return 0;
}