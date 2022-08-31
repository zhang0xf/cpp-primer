#include <iostream>
#include "SmallInt.h"

int main() {
    SmallInt si;

    si = 4;              // 首先将4隐式转换成SmallInt，然后调用SmallInt::operator=
    std::cout << si + 3; // 首先将si隐式转换成int,然后执行整数的加法

    // 内置类型转换将double实参转换成int
    // SmallInt sipi = 3.14; // 调用SmallInt(int)构造函数

    // compile error : error: implicit conversion from 'double' to 'int' changes value from 3.14 to 3 [-Werror,-Wliteral-conversion]

    // SmallInt的类型转换运算符将si转换成int
    // std::cout << sipi + 3.14; // 内置类型转换将所得的int继续转换为double

    SmallInt2 si2 = 3;
    // explicit:需要指明显示转换
    std::cout << static_cast<int>(si2) + 3;

    return 0;
}