#include "./hasPtr.h"

int main()
{
    HasPtr p("zahngfei");
    HasPtr p1(p);
    HasPtr p3 = p;

    HasPtr2 p2("hello world");
    HasPtr2 p4(p2);

    return 0;
}