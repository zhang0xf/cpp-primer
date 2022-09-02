#include <iostream>
#include "Quote.h"

Quote::Quote(const std::string &book, double sale_price) :
    bookNo(book), price(sale_price) {
}

std::string Quote::isbn() const {
    // std::cout << "use Quote::isbn()" << std::endl;
    return bookNo;
}

double Quote::net_price(std::size_t n) const {
    // std::cout << "use Quote::net_price()" << std::endl;
    return n * price;
}

Bulk_Quote::Bulk_Quote(const std::string &book, double p, std::size_t qty, double disc) :
    Quote(book, p), min_qty(qty), discount(disc) {
}

// 超过某个最低限额,即可享受折扣价格
// 可以访问共有和受保护成员
double Bulk_Quote::net_price(std::size_t cnt) const {
    // std::cout << "use Bulk_Quote::net_price()" << std::endl;
    if (cnt > min_qty) {
        return cnt * (1 - discount) * price;
    }
    return cnt * price;
}