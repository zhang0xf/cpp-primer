#include <set>
#include <string>
#include <iostream>
#include <map>

// 关联容器迭代器

void print_map(std::map<std::string, size_t> map)
{
    auto map_it = map.cbegin();
    while (map_it != map.cend())
    {
        // 打印关键字-值对
        std::cout << map_it->first << " occurs " << map_it->second << " times " << std::endl;
        ++map_it; // 递增迭代器
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