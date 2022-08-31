#include <iostream>

#include "./strBlob.h"
#include "./strBlobptr.h"

int main() {
    StrBlob sb({"zahngfei", "hello", "world", "test"});
    StrBlobPtr sbp = sb.begin();
    sbp.operator++(0);                     // 显示地调用后置版本的operator++
    sbp.operator++();                      // 调用前置版本
    std::cout << sbp.deref() << std::endl; // 输出begin()字符串

    return 0;
}