#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// val的阶乘
int fact(int val)
{
    int ret = 1;
    while (val > 1)
    {
        ret *= val--;
    }
    return ret;
}

int main()
{
    int r = fact(6);
    cout << "r! = " << r << endl;

    return 0;
}