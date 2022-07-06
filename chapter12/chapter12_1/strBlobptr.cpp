#include <stdexcept>

#include "./strBlobptr.h"

StrBlobPtr::StrBlobPtr() : curr(0) {}

StrBlobPtr::StrBlobPtr(StrBlob &a, size_t sz) : wptr(a.data), curr(sz) {}

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string &msg) const
{
    // 如果vector已销毁，lock将返回一个空指针。
    auto ret = wptr.lock(); // vector还存在么?
    if (!ret)
    {
        throw std::runtime_error("unbound StrBlobPtr");
    }
    else if (i >= ret->size())
    {
        throw std::out_of_range(msg);
    }
    return ret; // 否则,返回指向vector的shared_ptr
}

std::string &StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

// 前缀递增:返回递增后的对象的引用
StrBlobPtr &StrBlobPtr::incr()
{
    // 如果curr已经指向容器的尾后位置,则不能递增它
    check(curr, "increment past end of strBlobPtr");
    ++curr;
    return *this;
}