#include "./hasPtr.h"

int main()
{
    HasPtr p("zahngfei");
    HasPtr p1(p);
    HasPtr p3 = p;

    return 0;
}