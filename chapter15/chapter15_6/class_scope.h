#ifndef CLASS_SCOPE_H
#define CLASS_SCOPE_H

// 继承中的类作用域

struct Base {
    void memFunc() {
    }

    virtual void fcn() {
    }
};

// 即使派生类成员和基类成员的形参列表不一致,基类成员也仍然会被隐藏掉:
struct Derived : Base {
    void memFunc(int) { // 隐藏基类的memFunc
    }
};

class D1 : public Base {
public:
    // void fcn(int); // 隐藏基类的fcn,这个fcn不是虚函数 // 编译器有错误提示

    // D1继承了Base::fcn()的定义
    // ...

    // void fcn(int) { // 形参列表与base中的fcn不一致 // error: 编译器有错误提示
    // }

    virtual void f2() {
        // 是一个新的虚函数，在base中不存在
    }
};

class D2 : public D1 {
public:
    void fcn(int) { // 是一个非虚函数,隐藏了D1::fcn(int)
    }
    void fcn() { // 覆盖了base的虚函数fcn
    }
    void f2() { // 覆盖了D1的虚函数f2
    }
};

#endif