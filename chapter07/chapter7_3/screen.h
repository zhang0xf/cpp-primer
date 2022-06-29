#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <iostream>
#include <bitset>

class BitMap;
class Screen; // 申明

extern std::ostream &storeOn(std::ostream &, Screen &);
extern BitMap &storeOn(BitMap &, Screen &);

class Screen // 定义
{
    // 友元类:Window_mgr的成员函数可以访问Screen类的私有部分
    friend class Window_mgr;

    // 成员函数成员友元(注:需要重新组织程序结构以满足申明和定义的依赖关系)
    // friend void Window_mgr::clear(ScreenIndex);

    // 函数重载与友元
    friend std::ostream &storeOn(std::ostream &, Screen &); // 接受BitMap&做参数的版本仍然不能访问Screen

public:
    typedef std::string::size_type pos;  // 自定义类型在类中的别名
    using pos2 = std::string::size_type; // 等价申明

    Screen() = default; // 默认构造
    Screen(pos ht, pos wd, char ch) : height(ht), width(wd), contents(ht * wd, ch) {}

    char get() const { return contents[cursor]; } // 读取光标处的字符(隐式内联)
    inline char get(pos r, pos c) const;          // 显示内联
    Screen &move(pos r, pos c);                   // 能在之后被设置为内联
    Screen &set(char);
    Screen &set(pos, pos, char);

public:
    void some_member() const; // const成员函数与mutable成员

public:
    // 根据对象是否是const,重载了display函数
    Screen &display(std::ostream &os)
    {
        do_display(os); // 非常量版本调用do_display()时,this指针隐式地转换成指向常量的指针
        return *this;
    }

    const Screen &display(std::ostream &os) const
    {
        do_display(os); // display()的this指针隐式传递给do_display()
        return *this;
    }

private:
    // 该const成员函数显示Screen的内容
    void do_display(std::ostream &os) const { os << contents; }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

private:
    mutable size_t access_ctr; // 可变数据成员,即使在const内也能够修改
};

// 内联成员函数
// 注意:内联成员函数需要定义在头文件中!!!(另见6.5.2节)
char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}

inline Screen &Screen::move(pos r, pos c) // 在定义的地方说明inline,可以使类更容易理解
{
    pos row = r * width;
    cursor = row + c;
    return *this;
}

inline Screen &Screen::set(char ch)
{
    contents[cursor] = ch; // 设置当前光标所在位置的新值
    return *this;          // 左值返回(对象本身,而非副本)
}

inline Screen &Screen::set(pos r, pos col, char ch)
{
    contents[r * width + col] = ch; // 设置给定位置的新值
    return *this;                   // 左值返回
}

#endif