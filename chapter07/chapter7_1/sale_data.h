#ifndef SALE_DATA_H
#define SALE_DATA_H

#include <string>
#include <iostream>

struct Sales_Data
{
    // 构造函数
    Sales_Data() = default;                         // 默认构造函数
    Sales_Data(const std::string &s) : bookNo(s) {} // 初始值列表来初始化类成员,构造函数体为空
    Sales_Data(const std::string &s, unsigned n, double p) : bookNo(s), units_solds(n), revenue(n * p) {}
    Sales_Data(std::istream &); //初始值列表为空,但是执行了构造函数体,故对象仍能被初始化

    std::string isbn() const
    {
        return this->bookNo;
    } // const用于修饰this指针,指向常量对象,即在isbn的函数体内不会改变this所指的对象

    Sales_Data &combine(const Sales_Data &); // 类外定义
    double avg_price() const;                // 类外定义

    std::string bookNo;
    unsigned units_solds = 0; // 类内初始值
    double revenue = 0;       // 类内初始值
};

// Sales_Data的非成员接口函数(申明)
Sales_Data add(const Sales_Data &, const Sales_Data &);
std::ostream &print(std::ostream &, const Sales_Data &);
std::istream &read(std::istream &, Sales_Data &);

#endif
