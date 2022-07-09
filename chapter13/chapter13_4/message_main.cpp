#include "floder.h"

int main()
{
    Message msg1("hello world");
    Floder f1;
    msg1.save(f1);

    Message msg2("zahngfei");

    msg1 = msg2;

    Message msg3("test");
    Floder f2;
    msg3.save(f2);

    swap(msg1, msg3);

    return 0;
}