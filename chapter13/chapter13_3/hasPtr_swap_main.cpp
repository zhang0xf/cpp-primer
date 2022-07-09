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

    return 0;
}