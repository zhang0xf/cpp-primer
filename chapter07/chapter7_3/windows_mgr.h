#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include <vector>
#include "screen.h"

class Window_mgr
{
public:
    // 窗口中每个屏幕的编号
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);

private:
    // 这个Window_mgr追踪的Screen
    // 默认情况下,一个Window_mgr包含一个标准尺寸的空白Screen
    std::vector<Screen> screens{Screen(24, 80, ' ')}; // 类内初始值
};

#endif