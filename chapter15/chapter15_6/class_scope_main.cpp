#include "class_scope.h"

// 名字先于类型查找
// 因此,定义派生类中的函数也不会重载其基类中的成员.

int main() {
    Derived d;
    Base b;
    b.memFunc();   // 调用Base::memFunc()
    d.memFunc(10); // 调用Derived::memFunc()

    // d.memFunc(); // error: 被隐藏
    d.Base::memFunc(); // 正确: 调用Base::memFunc()

    Base bObj;
    D1 d1Obj;
    D2 d2Obj;

    Base *bp1 = &bObj;
    Base *bp2 = &d1Obj;
    Base *bp3 = &d2Obj;

    bp1->fcn(); // 虚调用,将在运行时调用Base::fcn()
    bp2->fcn(); // 虚调用,将在运行时调用Base::fcn()
    bp3->fcn(); // 虚调用,将在运行时调用D3::fcn()

    D1 *d1p = &d1Obj;
    D2 *d2p = &d2Obj;
    // bp2->f2(); // error: Base没有f2成员
    d1p->f2(); // 虚调用,将在运行时调用D1::f2()
    d2p->f2(); // 虚调用,将在运行时调用D2::f2()

    // Base *p1 = &d2Obj;
    // D1 *p2 = &d2Obj;
    D2 *p3 = &d2Obj;

    // p1.f1(10); // error: Base中没有接收int的fcn
    // p2->fcn(42); // 静态绑定: 调用D1::fcn(int)
    p3->fcn(42); // 静态绑定: 调用D2::fcn(int)

    return 0;
}