#ifndef ACCESS_CONTROL_H
#define ACCESS_CONTROL_H

#include <cstddef> // size_t

class Base {
    friend class pal; // pal在访问base派生类时,不具有特殊性

public:
    void pub_mem() {
        priv_mem = 'c';
    }

    std::size_t size() const {
        return n;
    }

protected:
    int prot_mem;
    std::size_t n;

private:
    char priv_mem;
};

// 派生类的成员或友元只能通过派生类对象来访问基类的受保护成员.
// 派生类对于一个基类对象中的受保护成员没有任何访问特权.
class Sneaky : public Base {
    friend void clobber(Sneaky &); // 可以访问Sneaky::port_name
    friend void clobber(Base &);   // 不能访问Base::port_name
    int j;                         // j默认是private
};

// 三种继承
// 派生访问说明符对于派生类的成员（及友元）能否访问其直接基类的成员没什么影响.对基类成员的访问权限只与基类中的访问说明符有关.
// 派生访问说明符的目的是控制派生类*用户*（包括派生类的派生类在内）对于基类成员的访问权限:

struct Pub_Dery : public Base {
    // 正确: 能访问protected成员
    int f() {
        return prot_mem;
    }

    // 错误: private成员对于派生类来说不可访问
    char g() {
        // return priv_mem;
        return 'a';
    }
};

struct Prot_Dery : protected Base {
    // 正确: 能访问protected成员
    int f() {
        return prot_mem;
    }

    // 错误: private成员对于派生类来说不可访问
    char g() {
        // return priv_mem;
        return 'a';
    }
};

struct Priv_Dery : private Base {
    // private 不影响派生类的访问权限
    int f() {
        return prot_mem;
    }

    char g() {
        // return priv_mem;
        return 'a';
    }
};

// 派生访问说明符还可以控制继承自派生类的新类的访问权限:
struct Dervied_from_Public : public Pub_Dery {
    // base::prot_mem在Pub_Dery仍然是protected的
    int use_base() {
        return prot_mem;
    }
};

struct Deried_from_private : public Priv_Dery {
    // 错误: base::prot_mem在Priv_Dery仍然是private的
    int use_base() {
        // return prot_mem
        return -1;
    }
};

struct Derived_from_protected : public Prot_Dery {
    int use_base() {
        pub_mem(); // protected(成员和友元可以访问,用户不可访问)
        return -1;
    }
};

// 友元与继承

class pal {
public:
    int f(Base b) {
        return b.prot_mem; // 正确: pal是base的友元
    }

    int f2(Sneaky s) {
        // return s.j; // 错误: pal不是Sneaky的友元
        // 对于基类的访问权限,由基类本身控制,即使对于派生类的基类部分也是如此
        return s.prot_mem; // 正确: pal是base的友元
    }
};

// 友元关系不能继承
class D2 : public pal {
public:
    int mem(Base b) {
        // return b.prot_mem; // 错误: 友元关系不能继承
        b.pub_mem();
        return 0;
    }
};

// 改变个别成员的可访问性
class Derived : private Base { // **注意**: private继承
public:
    // 保持对象尺寸相关的成员的访问级别
    using Base::size;

protected:
    using Base::n;
};

#endif