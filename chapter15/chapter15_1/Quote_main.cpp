#include <iostream>
#include "Quote.h"

// 计算并打印销售给定数量的某种书籍所得的费用
double print_total(std::ostream &os, const Quote &item, std::size_t n) {
    // 根据传入item形参的对象类型调用Quote::net_price()
    double ret = item.net_price(n);

    os << "ISBN : " << item.isbn()
       << "total due : " << ret << std::endl;

    return ret;
}

int main() {
    // basic类型是Quote, bulk类型是Bulk_Quote,
    Quote basic;
    Bulk_Quote bulk;

    print_total(std::cout, basic, 20);
    print_total(std::cout, bulk, 20);

    // 指针或引用绑定到派生类对象中的基类部分
    Quote *p = &basic; // P指向Quote对象
    std::cout << p->isbn() << std::endl;

    p = &bulk;       // p指向bulk中的Quote部分
    Quote &r = bulk; // r绑定到buil中的Quote部分
    std::cout << r.isbn() << std::endl;

    // 派生类和基类类型转换(指针和引用)
    // 派生类向基类转换
    Quote base;
    // Bulk_Quote *bulkP = &base; // error

    // 派生类和基类对象的转换
    // 构造函数只能处理处理基类自己的成员
    Bulk_Quote bulk2;
    Quote item(bulk2); // 构造函数(转换)
    item = bulk2;      // 赋值运算符(转换)
    std::cout << item.isbn() << std::endl;

    return 0;
}