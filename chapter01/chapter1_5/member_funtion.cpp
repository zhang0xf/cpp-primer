#include <iostream>
#include "sale_items.h"

int main()
{
    Sales_item item1, item2;
    std::cin >> item1 >> item2; // 读取交易记录

    // 检查是否表示相同的书
    if (item1.isbn() == item2.isbn())
    {
        std::cout << item1 + item2 << std::endl; // 打印和
        return 0;
    }
    else
    {
        std::cerr << "Data must refer to same ISBN " << std::endl;
        return -1;
    }

    return 0;
}