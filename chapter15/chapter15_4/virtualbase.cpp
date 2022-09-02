#include "virtualbase.h"

Quote::Quote(const std::string &book, double sale_price) :
    bookNo(book), price(sale_price) {
}

std::string Quote::isbn() const {
    return bookNo;
}

double Quote::net_price(std::size_t n) const {
    return n * price;
}

DiscQuote::DiscQuote(const std::string &book, double price, std::size_t qty, double disc) :
    Quote(book, price), quantity(qty), discount(disc) {
}

// 派生类的构造函数只初始化它的直接基类
BulkQuote::BulkQuote(const std::string &book, double price, std::size_t qty, double disc) :
    DiscQuote(book, price, qty, disc) {
}

double BulkQuote::net_price(std::size_t cnt) const {
    if (cnt > quantity) {
        return cnt * (1 - discount) * price;
    }
    return cnt * price;
}