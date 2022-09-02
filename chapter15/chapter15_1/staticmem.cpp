#include "staticmem.h"

void base::staticMem() {
    // do nothing
}

void Derived::f(const Derived &derived_obj) {
    base::staticMem();       // 正确: base定义了statmem
    Derived::staticMem();    // 正确: Derived继承了statmem
    derived_obj.staticMem(); // 正确: 通过派生类对象访问静态成员
    staticMem();             // 正确: 通过this指针访问
}