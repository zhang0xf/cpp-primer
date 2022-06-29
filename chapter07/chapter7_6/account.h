#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

// 类的静态成员
class Account
{
public:
    // 成员函数可以直接访问static变量
    void calculate() { amount += amount * interestRate; }

    static double rate() { return interestRate; } // 类内部定义静态成员函数
    static void rate(double);                     // 类外部定义静态成员函数
    Account &modify(double = interestRate);       // 静态数据成员可以做实参

private:
    std::string owner;
    double amount;
    static double interestRate;
    static double initRate();

    static constexpr int period = 30; // 静态成员的类内初始化,period是常量表达式
    double daliy_tbl[period];

    static Account account; // 静态数据成员可以是不完全类型
    Account *pAccount;      // 非静态成员只能使用指针或引用
};

#endif