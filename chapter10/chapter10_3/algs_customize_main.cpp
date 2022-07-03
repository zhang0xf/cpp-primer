#include <string>
#include <vector>
#include <algorithm>
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

// 比较函数,用来按照长度排序单词
bool isShorter(const string &s1, const string &s2) // 二元谓词!
{
    return s1.size() < s2.size();
}

// 排序并消除重复单词
void elimDups(vector<string> &words)
{
    std::sort(words.begin(), words.end());
    auto end_unique = std::unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

int main()
{
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};

    std::sort(words.begin(), words.end(), isShorter); // 只按照到长度大小排序,没有字典序

    print(words);

    elimDups(words); // 将words按照字典序排序,并消除重复

    // 按长度重新排序,长度相同的单词维持字典序
    // stable_sort:稳定排序算法,维持相等元素的原有顺序.
    std::stable_sort(words.begin(), words.end(), isShorter);

    print(words);

    return 0;
}
