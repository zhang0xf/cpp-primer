#ifndef OOP_VECTOR_H
#define OOP_VECTOR_H

#include <string>
#include <utility>
#include <iostream>

class Quote {
public:
    std::string isbn() const {
        return bookNo;
    }

    virtual Quote *clone() const & { // 引用限定符: 指出this的左值(&)/右值属性(&&) // 只能向可修改的左值赋值
        std::cout << "quote clone &" << std::endl;
        return new Quote(*this);
    }

    virtual Quote *clone() && { // 只能作用于右值
        std::cout << "quote clone &&" << std::endl;
        return new Quote(std::move(*this));
    }

    virtual ~Quote() {
    }

private:
    std::string bookNo;
};

class Bulk_Quote : public Quote {
public:
    // 覆盖虚函数
    virtual Bulk_Quote *clone() const & {
        std::cout << "Bulk_Quote clone &" << std::endl;
        return new Bulk_Quote(*this);
    }

    virtual Bulk_Quote *clone() && {
        std::cout << "Bulk_Quote clone &&" << std::endl;
        return new Bulk_Quote(std::move(*this));
    }

    virtual ~Bulk_Quote() {
    }
};

#endif