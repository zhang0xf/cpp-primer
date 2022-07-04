#include <iterator>
#include <iostream>

#include "./sale_items.h"

// input :
// 0-201-70353-X 4 24.99
// 0-201-78345-X 2 25.00

int main()
{
    std::istream_iterator<Sales_item> item_iter(std::cin), eof; // 绑定迭代器
    std::ostream_iterator<Sales_item> out_iter(std::cout, "\n");

    Sales_item sum = *item_iter++; // 将一笔交易记录保存在sum中,并读取下一条
    while (item_iter != eof)
    {
        if (item_iter->isbn() == sum.isbn())
        {
            sum += *item_iter++;
        }
        else
        {
            out_iter = sum;     // 输出当前值
            sum = *item_iter++; // 读取下一条
        }
    }
    out_iter = sum; // 打印最后一条记录

    return 0;
}