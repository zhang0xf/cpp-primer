#ifndef BASKET_H
#define BASKET_H

#include <memory>
#include <set>
#include <iostream>
#include "Quote.h"

class Basket {
public:
    // 隐藏指针
    void add_item(const Quote &); // 拷贝
    void add_item(Quote &&);      // 移动

    // Basket使用合成的默认构造函数和拷贝控制成员
    void add_item(const std::shared_ptr<Quote> &sale);
    // 打印每本书的总价和购物篮中所有书的总价
    double total_receipt(std::ostream &);

    double print_total(std::ostream &os, const Quote &item, std::size_t n) {
        double ret = 1.0 * n; // net_price()
        os << "ISBN : " << item.isbn()
           << "total due : " << ret << std::endl;
        return ret;
    }

private:
    // 该函数用于比较shared_ptr,multiset成员会使用到
    static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs) {
        return lhs->isbn() < rhs->isbn();
    }
    // std::multiset<std::shared_ptr<Quote>, decltype(ptrCompare) *> items(ptrCompare);
    std::multiset<std::shared_ptr<Quote>, decltype(compare) *> items{compare}; // 通过类内初始值调用比较函数
};

#endif