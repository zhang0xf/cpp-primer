#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H

#include <memory>
#include <vector>
#include <string>

#include "./strBlob.h"

// 核查指针类
class StrBlobPtr
{
public:
    StrBlobPtr();
    StrBlobPtr(StrBlob &a, size_t sz = 0);

    std::string &deref() const; // 解引用操作
    StrBlobPtr &incr();         // 前缀递增

private:
    // 若检查成功,check返回一个指向vector的shared_ptr
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
    // 保存一个weak_ptr意味着底层vector可能会被销毁
    std::weak_ptr<std::vector<std::string>> wptr; // 指向StrBlob的data成员,这是在初始化时提供给它的.
    std::size_t curr;                             // 在数组当中的当前位置
};

#endif