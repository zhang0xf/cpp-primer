#include "screen.h"

int main()
{
    Screen screen;
    screen.move(4, 0).set('#'); // 由于左值引用,所以合法且简洁

    const Screen blank(5, 3, ' ');
    screen.display(std::cout).set('#');
    screen.set('$').display(std::cout); // 调用非常量版本
    blank.display(std::cout);           // 调用常量版本

    const Screen c_screen(5, 3, ' ');
    c_screen.display(std::cout);
    return 0;
}