#include "sale_data.h"

using std::cin;

int main()
{
    Sales_data item;

    // 无explicit关键字
    item.combine(std::string("9-9999-9999-9")); // 显示地转换为string,隐式地转换为Sales_data
    item.combine(Sales_data("9-9999-9999-9"));  // 等价:隐式地转换为string.显示地转换为Sales_data
    item.combine(cin);                          // 隐式地将cin转换为Sales_data

    // 有explicit关键字
    // static_cast可以使用explicit的构造函数
    item.combine(static_cast<Sales_data>(cin));

    return 0;
}