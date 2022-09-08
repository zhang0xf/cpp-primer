#include <string>
#include "template_variadic.h"
#include "strVec.h"

int main() {
    int i = 0;
    double d = 3.14;
    std::string s = "how now brown cow";

    foo(i, s, 42, d); // 包中有三个参数
    foo(s, 42, "hi"); // 包中有2个参数
    foo(d, s);        // 包中有一个参数
    foo("hi");        // 空包

    errorMsg(std::cerr, "other");
    // errorMsg(std::cerr, debug_rep("other")); 等价

    StrVec svec;
    svec.emplace_back(10, 'c'); // 将cccccccccc添加为新的尾部元素

    return 0;
}