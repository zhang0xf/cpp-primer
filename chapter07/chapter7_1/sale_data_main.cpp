#include <iostream>
#include "sale_data.h"

using std::cerr;
using std::cin;
using std::cout;
using std::endl;

// input :
// 0-201-70353-X 4 24.99
// 0-201-78345-X 2 25.00

int main()
{
    Sales_Data total;
    if (read(cin, total))
    {
        Sales_Data trans;
        while (read(cin, trans))
        {
            if (total.isbn() == trans.isbn())
            {
                total.combine(trans); // 更新total当前值
            }
            else
            {
                print(cout, total) << endl; // 输出结果
                total = trans;              // 处理下一本
            }
        }
        print(cout, total) << endl; // 输出最后一条交易
    }
    else
    {
        cerr << "No Data?" << endl; // 通知用户
    }

    return 0;
}