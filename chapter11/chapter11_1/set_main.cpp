#include <set>
#include <string>
#include <iostream>
#include <map>

void print_map(std::map<std::string, size_t> map)
{
    for (const auto &m : map)
    {
        std::cout << m.first << " occurs " << m.second << ((m.second > 1) ? " times " : " time ") << std::endl;
    }
}

int main()
{
    std::map<std::string, size_t> word_count;
    std::set<std::string> exclude = {"The", "But", "And", "Or", "An"};

    std::string word;
    while (std::cin >> word)
    {
        // 只统计不在exclude中的单词
        if (exclude.find(word) == exclude.end())
        {
            ++word_count[word];
        }
    }

    print_map(word_count);
    return 0;
}