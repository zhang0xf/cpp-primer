#include <map>
#include <string>
#include <unordered_set>

#include "../sale_items.h"

using std::map;
using std::string;

// hash值计算函数
size_t hasher(const Sales_item &s)
{
    return std::hash<string>()(s.isbn()); // 计算isbn的哈希值
}

// 自定义类型==运算符
bool eqOp(const Sales_item &s1, const Sales_item &s2)
{
    return s1.isbn() == s2.isbn();
}

int main()
{
    // 定义一个unordered_multiset
    using SD_multiset = std::unordered_multiset<Sales_item, decltype(hasher) *, decltype(eqOp) *>; // 简化类型名
    // 参数是桶大小(42)、哈希函数指针、相等性判断运算符指针
    SD_multiset book_store(42, hasher, eqOp);

    // 如果类(Sales_item)定义了==运算符,则可以只重载哈希函数
    // 略 ...

    return 0;
}