#include <string>
#include <iostream>

using std::string;

int main()
{
    string numbers("0123456789"), name("r2d2");

    string::size_type pos = 0;

    // string.find()查找不到结果,即返回npos
    // param:pos:表示从下标pos开始搜索(默认是0)
    while ((pos = name.find_first_of(numbers, pos)) != string::npos)
    {
        std::cout << "found number at index : " << pos << " element is " << name[pos] << std::endl;
        ++pos;
    }

    return 0;
}