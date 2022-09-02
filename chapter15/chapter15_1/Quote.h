#ifndef QUOTE_H
#define QUOTE_H

#include <string>

// 面向对象程序设计

// 基类
class Quote {
public:
    Quote() = default;
    Quote(const std::string &book, double sale_price);

    std::string isbn() const;
    // 返回给定数量的书籍的销售总额
    // 派生类负责改写, 并使用不同的折扣计算算法
    virtual double net_price(std::size_t n) const;

    virtual ~Quote() = default; // 对析构函数进行动态绑定

private:                // 派生类不能访问私有成员
    std::string bookNo; // 书籍的ISBN编号

protected:              // 派生类需要访问price，同时禁止其他用户访问.
    double price = 0.0; // 代表普通状态下不打折的价格
};

// 派生类
class Bulk_Quote : public Quote { // 可以是基类列表
public:
    Bulk_Quote() = default;
    Bulk_Quote(const std::string &, double, std::size_t, double);

    // 覆盖基类的函数版本以实现基于大量购买的折扣政策.
    virtual double net_price(std::size_t cnt) const override;

private:
    std::size_t min_qty = 0; // 使用折扣政策的最低购买量
    double discount = 0.0;   // 小数表示的折扣额
};

#endif