#include <set>
#include <string>
#include <iostream>
#include <map>

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

    std::string word;
    std::cin >> word;

    // 包含不重复关键字,所以插入一个已存在的元素对容器没有任何影响.
    word_count.insert({word, 1});
    word_count.insert(std::make_pair(word, 1));                            // 等价插入
    word_count.insert(std::pair<std::string, size_t>(word, 1));            // 等价插入
    word_count.insert(std::map<std::string, size_t>::value_type(word, 1)); // 等价插入

    // 检查insert返回值(pair)
    auto ret = word_count.insert(std::make_pair(word, 1));
    if (ret.second)
    {
        std::cout << "insert success!" << std::endl;
    }
    else
    {
        std::cout << "insert failure!" << std::endl;
        ++ret.first->second; // 递增计数器(key相同,value++)
    }

    print_map(word_count);
    return 0;
}