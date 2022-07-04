#include <string>
#include <iostream>
#include <map>

// 下标或at()函数不适用于multimap

int main()
{
    std::map<std::string, size_t> word_count;
    word_count["Anna"] = 1; // 不存在会插入这个新值
    word_count.at("Anna");  // 若Anna不在map中,则抛出一个out_of_range异常

    const std::map<std::string, size_t> word_count2;
    // word_count2["Anna"] = 2; // 常量map不能使用下标运算

    return 0;
}