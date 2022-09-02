#ifndef OVERDIDE_H
#define OVERDIDE_H

// 虚函数

// 在C++11新标准中我们可以使用override关键字来说明派生类中的虚函数.
// 这么做的好处是在使得程序员的意图更加清晰的同时让编译器可以为我们发现一些错误,后者在编程实践中显得更加重要.
// 如果我们使用override标记了某个函数,但该函数并没有覆盖已存在的虚函数,此时编译器将报错:

struct B {
    virtual void f1(int) const;
    virtual void f2();
    void f3();
};

struct D1 : public B {
    void f1(int) const override; // 正确: f1与基类中的f1匹配
    // void f2(int) override;       // 错误: B没有形如f2(int)的函数
    // void f3() override;          // 错误: f3()不是虚函数
    // void f4() override;          // 错误: B没有名为f4的函数
};

// 我们还能把某个函数指定为final,如果我们已经把函数定义成final了,则之后任何尝试覆盖该函数的操作都将引发错误:
struct D2 : B {
    // 从B继承f2()和f3(),覆盖f1(int)
    void f1(int) const final; // 不允许后续的其他类覆盖f1(int)
};

struct D3 : D2 {
    void f2(); // 正确: 覆盖从间接基类B继承而来的f2
    // void f1(int) const; // 错误: D2已经将f2声明称final
};

#endif