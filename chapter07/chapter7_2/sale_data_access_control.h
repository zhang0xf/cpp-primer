#ifndef SALE_DATA_H
#define SALE_DATA_H

#include <string>
#include <iostream>

// 移植于Sales_Data

class Sales_Data_Access_Control // 使用class关键字
{
    // 为Sales_Data_Access_Control非成员函数所作的友元申明
    friend Sales_Data_Access_Control add(const Sales_Data_Access_Control &, const Sales_Data_Access_Control &);
    friend std::ostream &print(std::ostream &, const Sales_Data_Access_Control &);
    friend std::istream &read(std::istream &, Sales_Data_Access_Control &);

public: // 添加了访问控制符
    Sales_Data_Access_Control() = default;
    Sales_Data_Access_Control(const std::string &s) : bookNo(s) {}
    Sales_Data_Access_Control(const std::string &s, unsigned n, double p) : bookNo(s), units_solds(n), revenue(n * p) {}
    Sales_Data_Access_Control(std::istream &);

    std::string isbn() const
    {
        return this->bookNo;
    }
    Sales_Data_Access_Control &combine(const Sales_Data_Access_Control &);

private: // 添加了访问控制符
    double avg_price() const;

    std::string bookNo;
    unsigned units_solds = 0;
    double revenue = 0;
};

// Sales_Data_Access_Control非成员函数申明
Sales_Data_Access_Control add(const Sales_Data_Access_Control &, const Sales_Data_Access_Control &);
std::ostream &print(std::ostream &, const Sales_Data_Access_Control &);
std::istream &read(std::istream &, Sales_Data_Access_Control &);

#endif
