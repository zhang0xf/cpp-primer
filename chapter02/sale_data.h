#ifndef SALE_DATA_H // 防止头文件重复包含
#define SALE_DATA_H

#include <string>

struct Sales_Data
{
    std::string bookNo;
    unsigned units_solds = 0;
    double revenue = 0;
};

#endif