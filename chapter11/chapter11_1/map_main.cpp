#include <map>
#include <string>
#include <iostream>

// 单词计数程序

void print_map(std::map<std::string, size_t> map)
{
    for (const auto &m : map)
    {
        std::cout << m.first << " occurs " << m.second << ((m.second > 1) ? " times " : " time ") << std::endl;
    }
}

int main()
{
    std::map<std::string, size_t> word_count; // 统计每个单词在输入中出现的次数
    std::string word;

    while (std::cin >> word)
    {
        ++word_count[word]; // 计数++
    }

    print_map(word_count);

    return 0;
}