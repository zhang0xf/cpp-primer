#include "./hasPtr.h"

int main()
{
    HasPtr p("zhangfei");
    HasPtr p2("hello world");

    p.print();
    p2.print();

    swap(p, p2);

    p.print();
    p2.print();

    HasPtr p3 = p;
    p3.print();

    return 0;
}