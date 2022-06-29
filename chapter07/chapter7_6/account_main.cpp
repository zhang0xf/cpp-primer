#include <iostream>
#include "account.h"

int main()
{
    // 使用静态成员
    double r;
    r = Account::rate();
    std::cout << r << std::endl;

    Account ac1;
    Account *ac2 = &ac1;
    r = ac1.rate();  // 对象或引用
    r = ac2->rate(); // 对象的指针

    return 0;
}