#ifndef SALE_DATA_H
#define SALE_DATA_H

#include <string>
#include <iostream>

// 另见chapter7_2
class Sales_Data
{
    friend Sales_Data add(const Sales_Data &, const Sales_Data &);
    friend std::ostream &print(std::ostream &, const Sales_Data &);
    friend std::istream &read(std::istream &, Sales_Data &);

public:
    Sales_Data() = default;
    Sales_Data(const std::string &s) : bookNo(s) {}
    Sales_Data(const std::string &s, unsigned n, double p) : bookNo(s), units_solds(n), revenue(n * p) {}
    Sales_Data(std::istream &);

    std::string isbn() const
    {
        return this->bookNo;
    }
    Sales_Data &combine(const Sales_Data &);

private:
    double avg_price() const;

    std::string bookNo;
    unsigned units_solds = 0;
    double revenue = 0;
};

Sales_Data add(const Sales_Data &, const Sales_Data &);
std::ostream &print(std::ostream &, const Sales_Data &);
std::istream &read(std::istream &, Sales_Data &);

#endif
