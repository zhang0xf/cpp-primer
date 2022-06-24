#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // sort

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::string;
using std::vector;

bool binarySearch(vector<string> v, string s)
{
    if (v.empty() || s.empty())
    {
        return false;
    }

    std::sort(v.begin(), v.end());

    auto begin = v.begin(), end = v.end();
    auto mid = v.begin() + (end - begin) / 2; // 迭代器的运算

    while (mid != end && *mid != s)
    {
        if (s < *mid)
        {
            end = mid;
        }
        else
        {
            begin = mid + 1;
        }
        mid = begin + (end - begin) / 2; // 新的中点
    }

    // 循环结束时, mid指向end或寻找的元素
    if (mid == end)
    {
        return false;
    }
    return true;
}

int main()
{
    vector<string> text; // 二分查找:text必须有序

    text.push_back("hello world5");
    text.push_back("hello world1");
    text.push_back("hello world2");
    text.push_back("hello world3");
    text.push_back("hello world4");

    cout << binarySearch(text, "hello world5") << endl;
    cout << binarySearch(text, "hello world0") << endl;

    return 0;
}