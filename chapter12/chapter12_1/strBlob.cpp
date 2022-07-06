#include <stdexcept>

#include "./strBlob.h"
#include "./strBlobptr.h"

// 构造函数
// 指向一个动态分配的空vector
StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
// 指向一个动态分配的vector,使用initializer_list初始化
StrBlob::StrBlob(std::initializer_list<std::string> li) : data(std::make_shared<std::vector<std::string>>(li)) {}

// 元素访问通用逻辑
void StrBlob::check(size_type i, const std::string &msg) const
{
    if (i >= data->size())
    {
        throw std::out_of_range(msg);
    }
}

std::string &StrBlob::front()
{
    // 如果vector为空,check会抛出一个异常
    check(0, "front on empty stdBlob");
    return data->front();
}

std::string &StrBlob::back()
{
    // 如果vector为空,check会抛出一个异常
    check(0, "back on empty stdBlob");
    return data->back();
}

void StrBlob::pop_back()
{
    // 如果vector为空,check会抛出一个异常
    check(0, "pop_back on empty stdBlob");
    data->pop_back();
}

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

// 核查指针类
// std::shared_ptr<std::vector<std::string>>
// StrBlobPtr::check(std::size_t i, const std::string &msg) const
// {
//     // 如果vector已销毁，lock将返回一个空指针。
//     auto ret = wptr.lock(); // vector还存在么?
//     if (!ret)
//     {
//         throw std::runtime_error("unbound StrBlobPtr");
//     }
//     else if (i >= ret->size())
//     {
//         throw std::out_of_range(msg);
//     }
//     return ret; // 否则,返回指向vector的shared_ptr
// }

// std::string &StrBlobPtr::deref() const
// {
//     auto p = check(curr, "dereference past end");
//     return (*p)[curr];
// }

// // 前缀递增:返回递增后的对象的引用
// StrBlobPtr &StrBlobPtr::incr()
// {
//     // 如果curr已经指向容器的尾后位置,则不能递增它
//     check(curr, "increment past end of strBlobPtr");
//     ++curr;
//     return *this;
// }