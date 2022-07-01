#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;

void print(vector<string> vec)
{
    for (const auto &it : vec)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
}

// 消除重复单词
void elimDups(vector<string> &words)
{
    // 按字典序排列words,以便查找重复单词
    std::sort(words.begin(), words.end());

    // unique重排输入范围,使得每个单词只出现一次
    // 排列在范围的前部,返回指向不重复区域之后一个位置的迭代器
    auto end_unique = std::unique(words.begin(), words.end());

    // 使用向量操作erase删除重复
    // 因为算法不改变容器(增加、删除元素)
    words.erase(end_unique, words.end());
}

int main()
{
    vector<string> vec = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};

    elimDups(vec);

    print(vec);

    return 0;
}