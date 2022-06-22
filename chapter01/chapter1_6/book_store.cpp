#include <iostream>
#include "../sale_items.h"

// 书店程序

int main()
{
    Sales_item total;

    if (std::cin >> total)
    {
        Sales_item trans;

        while (std::cin >> trans)
        {
            if (total.isbn() == trans.isbn())
            {
                total += trans;
            }
            else
            {
                std::cout << total << std::endl;
                total = trans;
            }
        }
        std::cout << total << std::endl; // 打印最后一本书的销量
    }
    else
    {
        std::cerr << "No Data!" << std::endl;
        return -1; // 表示失败
    }

    return 0;
}