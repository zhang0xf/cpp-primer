#ifndef VIRTUAL_BASE_H
#define VIRTUAL_BASE_H

#include <string>

// 基类
class Quote {
public:
    Quote() = default;
    Quote(const std::string &book, double sale_price);

    std::string isbn() const;
    virtual double net_price(std::size_t n) const;

    virtual ~Quote() = default;

private:
    std::string bookNo;

protected:
    double price = 0.0;
};

// 抽象基类

// 用于保存折扣值和购买量的类,派生类使用这些数据可以实现不同的价格策略
class DiscQuote : public Quote {
public:
    DiscQuote() = default;
    DiscQuote(const std::string &, double, std::size_t, double);
    // 当前这个net_price函数没有实际意义(每个派生类通过定义自己的net_price函数,实现各自的折扣策略)
    virtual double net_price(std::size_t) const = 0; // 纯虚函数

protected:
    std::size_t quantity = 0; // 折扣适用的购买量
    double discount = 0.0;    // 表示折扣的小数值
};

class BulkQuote : public DiscQuote {
public:
    BulkQuote() = default;
    // 派生类的构造函数只初始化它的直接基类
    BulkQuote(const std::string &, double, std::size_t, double);
    // 覆盖基类中的函数版本以实现一种新的折扣策略
    virtual double net_price(std::size_t) const override;

private:
};

#endif