#include "windows_mgr.h"

void Window_mgr::clear(ScreenIndex index)
{
    // s指向我们想清空的那个屏幕
    Screen &s = screens[index];
    // 将选定的那个screen重置为空白
    s.contents = std::string(s.height * s.width, ' ');
}
