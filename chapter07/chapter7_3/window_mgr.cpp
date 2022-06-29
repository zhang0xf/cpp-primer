#include "windows_mgr.h"

void Window_mgr::clear(ScreenIndex index)
{
    // s指向我们想清空的那个屏幕
    Screen &s = screens[index];
    // 将选定的那个screen重置为空白
    s.contents = std::string(s.height * s.width, ' ');
}

// 类作用域:首先处理返回类型,之后我们才进入Window_mgr作用域
Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen &screen)
{
    screens.push_back(screen);
    return screens.size() - 1;
}