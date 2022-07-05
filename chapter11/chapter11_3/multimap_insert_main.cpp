#include <string>
#include <iostream>
#include <map>

int main()
{
    std::multimap<std::string, std::string> authors;
    // 相同作者的不同著作
    authors.insert({"barth john", "Sot-Weed Factor"});
    authors.insert({"barth john", "Lost in the funHouse"});

    return 0;
}