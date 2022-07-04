#include <utility> // pair头文件
#include <string>
#include <iostream>
#include <vector>

// 返回pair
std::pair<std::string, int> process(std::vector<std::string> &vec)
{
    // 返回一个由v中最后一个string及其大小组成的pair
    if (!vec.empty())
    {
        return {vec.back(), vec.back().size()};
        return std::make_pair(vec.back(), vec.back().size()); // 等价
    }
    else
    {
        return std::pair<std::string, int>(); // 隐式构造返回值
    }
}

int main()
{
    std::pair<std::string, std::string> author{"zhangfei", "James"};
    std::pair<std::string, std::string> author2("zhangfei", "James"); // 等价定义

    std::make_pair("zhangfei", 18); // pair类型根据成员类型自动推断

    // 打印结果
    std::cout << author.first << author.second << std::endl;

    std::vector<std::string> words = {"zahngfei", "hello world"};

    process(words);

    return 0;
}