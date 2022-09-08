#include <iostream>
#include "template_match.h"

int main() {
    std::string s("hi");

    std::cout << debug_rep(s) << std::endl;
    std::cout << debug_rep(&s) << std::endl; // 两个版本都可以匹配, 第二个版本是精确匹配.

    std::cout << debug_rep("hello world") << std::endl;

    return 0;
}