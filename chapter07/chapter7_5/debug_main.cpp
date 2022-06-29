#include "debug.h"

int main()
{
    Deubg io_sub(false, true, false); // 调试io
    if (io_sub.any())                 // 等价于if(true)
    {
        std::cerr << "error message : " << std::endl;
    }

    return 0;
}