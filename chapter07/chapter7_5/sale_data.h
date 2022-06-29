#ifndef SALE_DTAT_H
#define SALE_DTAT_H

#include <iostream>
#include <string>

class Sales_data
{
    friend std::istream &read(std::istream &, Sales_data &);

public:
    // 非委托构造函数使用对应的实参舒适化成员
    Sales_data(std::string s, unsigned cnt, double price) : bookNo(s), units_solds(cnt), revenue(cnt * price) {}

    // 其余构造函数全都委托给另一个构造函数
    Sales_data() : Sales_data("", 0, 0) {}
    Sales_data(std::string s) : Sales_data(s, 0, 0) {}
    Sales_data(std::istream &is) : Sales_data() { read(is, *this); }

    // explicit:抑制构造函数定义的隐式转换(另见sale_data_main.cpp)
    // explicit只对一个实参的构造函数有效,多个实参的构造函数本身不能用于执行隐式转换,故无需explicit
    // explicit只能用于直接初始化
    // explicit Sales_data(std::string s) : Sales_data(s, 0, 0) {}
    // explicit Sales_data(std::istream &is) : Sales_data() { read(is, *this); }

    Sales_data &combine(const Sales_data &);

private:
    std::string bookNo;
    unsigned units_solds = 0;
    double revenue = 0;
};

#endif