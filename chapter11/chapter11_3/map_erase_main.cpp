#include <string>
#include <iostream>
#include <map>

int main()
{
    std::multimap<std::string, std::string> authors;
    authors.insert({"barth john", "Sot-Weed Factor"});
    authors.insert({"barth john", "Lost in the funHouse"}); // key相同,value不同

    // 保存重复关键字的容器,erase返回删除元素的数量(可能大于1)
    auto cnt = authors.erase("barth john"); // 参数为关键字(也可以是迭代器,或一对迭代器)
    if (cnt)
    {
        std::cout << "delete " << cnt << " barth john " << std::endl;
    }
    else
    {
        std::cout << "not found "
                  << "barth john" << std::endl;
    }

    // 对于不重复关键字的容器,erase总是返回0或1
    // 略

    return 0;
}