#include <iostream>
#include <stdexcept> // 标准异常

#include "sale_items.h"

using std::cin;
using std::cout;
using std::endl;

Sales_item addTwoSaleItems(Sales_item &item1, Sales_item &item2)
{
    if (item1.isbn() != item2.isbn())
    {
        throw std::runtime_error("Data must refer to same ISBN!");
    }

    return item1 + item2;
}

int main()
{
    Sales_item item1, item2;

    while (cin >> item1 >> item2)
    {
        try
        {
            addTwoSaleItems(item1, item2);
        }
        catch (std::runtime_error err)
        {
            cout << err.what()
                 << "\nTry Again? Enter y or n" << endl;

            char ch;
            cin >> ch;
            if (!cin || ch == 'n')
            {
                break;
            }
        }
    }

    return 0;
}