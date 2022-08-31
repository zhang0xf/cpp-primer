#include <stdexcept>

#include "./strBlobptr.h"

StrBlobPtr::StrBlobPtr() :
    curr(0) {
}

StrBlobPtr::StrBlobPtr(StrBlob &a, size_t sz) :
    wptr(a.data), curr(sz) {
}

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string &msg) const {
    // 如果vector已销毁，lock将返回一个空指针。
    auto ret = wptr.lock(); // vector还存在么?
    if (!ret) {
        throw std::runtime_error("unbound StrBlobPtr");
    } else if (i >= ret->size()) {
        throw std::out_of_range(msg);
    }
    return ret; // 否则,返回指向vector的shared_ptr
}

std::string &StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

// 前缀递增:返回递增后的对象的引用
StrBlobPtr &StrBlobPtr::incr() {
    // 如果curr已经指向容器的尾后位置,则不能递增它
    check(curr, "increment past end of strBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr &StrBlobPtr::operator++() {
    // 如果curr已经指向容器的尾后位置,则不能递增它
    check(curr, "increment past end of strBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr &StrBlobPtr::operator--() {
    // 如果curr是0,则继续递减它将产生一个无效的下标
    --curr;
    check(curr, "increment past end of strBlobPtr");
    return *this;
}

// 后置版本++运算符重载
// 调用前置版本来完成计算
// 不会使用int形参
StrBlobPtr StrBlobPtr::operator++(int) {
    // 此处无需检查有效性,调用前置递增运算符时才需要检查
    StrBlobPtr ret = *this;
    ++*this; // 向前移动一个元素,前置++需要检查递增的有效性
    return ret;
}

StrBlobPtr StrBlobPtr::operator--(int) {
    // 此处无需检查有效性,调用前置递减运算符时才需要检查
    StrBlobPtr ret = *this;
    --*this; // 向前移动一个元素,前置++需要检查递增的有效性
    return ret;
}