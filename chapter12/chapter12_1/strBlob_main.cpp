#include <iostream>

#include "./strBlob.h"

using std::cout;
using std::endl;

int main()
{
    StrBlob b;
    StrBlob c;

    StrBlob blob({"zhangfei", "hello world", "test"});
    StrBlob blob2(blob); //增加引用计数

    cout << blob.back() << endl;

    blob = b; // 减少引用计数(blob指向新值)
    blob2 = c;

    cout << blob.back() << endl; // 抛出异常!!!

    return 0;
}