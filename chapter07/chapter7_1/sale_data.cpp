#include "sale_data.h"

using std::istream;
using std::ostream;

// 类外定义构造函数
Sales_Data::Sales_Data(std::istream &is)
{
    read(is, *this); // 从is中读取一条交易信息,然后存入this对象中
}

// 类外定义成员函数
double Sales_Data::avg_price() const // 作用域运算符::,表明avg_price()函数位于Sales_Data类的作用域内,即可以使用units_solds和revenue
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

Sales_Data &Sales_Data::combine(const Sales_Data &rhs) // 返回左值引用(尽量模仿赋值运算符)
{
    units_solds += rhs.units_solds;
    revenue += rhs.revenue;
    return *this; //  返回调用该函数的对象
}

// 非成员接口函数
istream &read(istream &is, Sales_Data &item) // io类属于不可拷贝的对象,故需使用引用,且读取和写入会改变流的内容,故使用普通的引用.
{
    double price = 0;
    is >> item.bookNo >> item.units_solds >> price;
    item.revenue = price * item.units_solds;
    return is;
}

ostream &print(ostream &os, const Sales_Data &item)
{
    os << item.isbn() << " " << item.units_solds << " "
       << item.revenue << " " << item.avg_price(); // 不负责换行,减少对格式的控制

    return os;
}

Sales_Data add(const Sales_Data &lhs, const Sales_Data &rhs)
{
    Sales_Data sum = lhs;
    sum.combine(rhs);
    return sum;
}
