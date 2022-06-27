#include "sale_data_access_control.h"

using std::istream;
using std::ostream;

// 类外定义构造函数
Sales_Data_Access_Control::Sales_Data_Access_Control(std::istream &is)
{
    read(is, *this);
}

// 类外定义成员函数
double Sales_Data_Access_Control::avg_price() const
{
    if (units_solds)
    {
        return revenue / units_solds;
    }
    else
    {
        return 0;
    }
}

Sales_Data_Access_Control &Sales_Data_Access_Control::combine(const Sales_Data_Access_Control &rhs)
{
    units_solds += rhs.units_solds;
    revenue += rhs.revenue;
    return *this;
}

// 非成员接口函数
istream &read(istream &is, Sales_Data_Access_Control &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_solds >> price;
    item.revenue = price * item.units_solds;
    return is;
}

ostream &print(ostream &os, const Sales_Data_Access_Control &item)
{
    os << item.isbn() << " " << item.units_solds << " "
       << item.revenue << " " << item.avg_price();

    return os;
}

Sales_Data_Access_Control add(const Sales_Data_Access_Control &lhs, const Sales_Data_Access_Control &rhs)
{
    Sales_Data_Access_Control sum = lhs;
    sum.combine(rhs);
    return sum;
}
