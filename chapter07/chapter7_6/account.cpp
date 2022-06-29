#include "account.h"

// *定义*并初始化一个静态成员
double Account::interestRate = initRate();

double Account::initRate()
{
    interestRate = 0.0;
    return interestRate;
}

// 一个不带初始值的静态成员的*定义*
constexpr int Account::period; // 初始值在类的定义内提供

// 类外部定义静态成员函数
void Account::rate(double newRate)
{
    interestRate = newRate;
}