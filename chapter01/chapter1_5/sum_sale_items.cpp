#include <iostream>
#include "../sale_items.h"

// input :
// 0-201-70353-X 4 24.99
// 0-201-78345-X 2 25.00

int main()
{
    Sales_item item1, item2;
    std::cin >> item1 >> item2;              // 读取交易记录
    std::cout << item1 + item2 << std::endl; // 打印和
    return 0;
}