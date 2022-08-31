#ifndef SMALL_INT_H
#define SMALL_INT_H

#include <stdexcept>

class SmallInt {
public:
    SmallInt(int i = 0) :
        val(i) {
        if (i < 0 || i > 255) {
            throw std::out_of_range("Bad SmallInt value");
        }
    }

    // 类型转换运算符
    // 没有显式的返回类型,也没有形参,且必是成员函数
    operator int() const {
        return val;
    }

private:
    int val;
};

class SmallInt2 {
public:
    SmallInt2(int i = 0) :
        val(i) {
        if (i < 0 || i > 255) {
            throw std::out_of_range("Bad SmallInt value");
        }
    }

    // 类型转换运算符
    // 没有显式的返回类型,也没有形参,且必是成员函数
    // explicit : 禁止隐式转换
    explicit operator int() const {
        return val;
    }

private:
    int val;
};

#endif