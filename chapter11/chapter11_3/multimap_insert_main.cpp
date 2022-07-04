#include <string>
#include <iostream>
#include <map>

int main()
{
    std::multimap<std::string, std::string> authors;
    authors.insert({"barth john", "Sot-Weed Factor"});
    authors.insert({"barth john", "Lost in the funHouse"}); // key相同,value不同

    return 0;
}