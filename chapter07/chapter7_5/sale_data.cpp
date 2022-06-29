#include "sale_data.h"

std::istream &read(std::istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_solds >> price;
    item.revenue = price * item.units_solds;
    return is;
}

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_solds += rhs.units_solds;
    revenue += rhs.revenue;
    return *this;
}
