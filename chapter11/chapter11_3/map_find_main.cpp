#include <string>
#include <iostream>
#include <map>

// 使用find和count
void find1(std::multimap<std::string, std::string> authors, std::string search_item)
{
    auto entries = authors.count(search_item); // 元素数量

    auto iter = authors.find(search_item); // 此作者的第一本书

    // 使用循环查找作者的所有著作
    while (entries)
    {
        std::cout << iter->second << std::endl;
        ++iter;
        --entries;
    }
}

// 面向迭代器的方案
void find2(std::multimap<std::string, std::string> authors, std::string search_item)
{
    // beg和end表示此作者的著作范围
    // 关键字不存在,则lower_bound = upper_bound
    for (auto beg = authors.lower_bound(search_item),
              end = authors.upper_bound(search_item);
         beg != end; ++beg)
    {
        std::cout << beg->second << std::endl;
    }
}

// 使用equal_range函数
void find3(std::multimap<std::string, std::string> authors, std::string search_item)
{
    for (auto pos = authors.equal_range(search_item); pos.first != pos.second; ++pos.first)
    {
        std::cout << pos.first->second << std::endl; // 打印著作(second)
    }
}

int main()
{
    std::multimap<std::string, std::string> authors;
    authors.insert({"barth john", "Sot-Weed Factor"});
    authors.insert({"barth john", "Lost in the funHouse"});

    std::string search_item("barth john"); // 要查找的作者

    find1(authors, search_item);

    find2(authors, search_item);

    find3(authors, search_item);

    return 0;
}