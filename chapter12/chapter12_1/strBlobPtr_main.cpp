#include <iostream>

#include "./strBlob.h"
#include "./strBlobptr.h"

int main()
{
    StrBlob sb({"zahngfei", "hello", "world", "test"});
    StrBlobPtr sbp = sb.begin();
    std::cout << sbp.deref() << std::endl; // 输出begin()字符串

    return 0;
}