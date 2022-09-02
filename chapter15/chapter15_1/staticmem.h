#ifndef STATIC_MEM_H
#define STATIC_MEM_H

// 静态成员的继承

class base {
public:
    static void staticMem(); // 唯一实例
};

class Derived : public base {
    void f(const Derived &);
};

#endif