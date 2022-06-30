#include <iostream>
#include <sstream>
#include "person.h"

// string流
bool valid(std::string nums)
{
    // TODO:
    nums = "";
    return false;
}

std::string format(std::string nums)
{
    return nums;
}

int main()
{
    std::string line, word;
    std::vector<PersonInfo> people;

    // 逐行从cin读取数据,直至cin遇到文件尾(或其他错误)
    while (getline(std::cin, line))
    {
        PersonInfo info;                 // 创建一个保存此记录数据的对象
        std::istringstream record(line); // 将记录绑定到刚读入的行
        record >> info.name;
        while (record >> word) // 读取电话号码(从string流中读取数据,全部数据读出后,同样会触发"文件结束")
        {
            info.phones.push_back(word); // 保存电话号码
        }
        people.push_back(info);
    }

    // 逐个验证电话号码,并改变其格式
    for (const auto &entry : people)
    {
        std::ostringstream formatted, badNum;
        for (const auto &nums : entry.phones)
        {
            if (!valid(nums))
            {
                badNum << " " << nums; // 将数的字符串形式存入badNum
            }
            else
            {
                formatted << " " << format(nums); // 将格式化的字符串"写入"formatted
            }
        }

        if (badNum.str().empty())
        {
            // std::cout也可以是别的os对象(特别地,是写入文件的os)
            std::cout << entry.name << " " << formatted.str() << std::endl; // 打印名字和格式化的数
            // os << entry.name << " " << formatted.str() << std::endl;        // 打印名字和格式化的数
        }
        else
        {
            std::cerr << "input error: " << entry.name << " invalid number(s) " << badNum.str() << std::endl; // 打印名字和错误的数
        }
    }

    return 0;
}