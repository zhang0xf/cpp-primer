#include <string>
#include <iostream>
#include <map>

int main()
{
    std::multimap<std::string, std::string> authors;
    // 相同作者的不同著作
    authors.insert({"barth john", "Sot-Weed Factor"});
    authors.insert({"barth john", "Lost in the funHouse"});

    // 保存重复关键字的容器,erase返回删除元素的数量(可能大于1)
    auto cnt = authors.erase("barth john"); // erase参数为"关键字"(也可以是迭代器,或一对迭代器)
    if (cnt)
    {
        std::cout << "delete " << cnt << " barth john " << std::endl;
    }
    else
    {
        std::cout << "not found " << std::endl;
    }

    return 0;
}