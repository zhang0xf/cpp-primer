#ifndef TEMPLATE_SPECIAL_H
#define TEMPLATE_SPECIAL_H

#include <cstring>
#include "sale_items.h"

// compare不能处理字符数组类型
template <typename T>
int compare(const T &, const T &);

// compare的特殊版本,处理字符数组的指针
template <> // 注意空的尖括号
int compare(const char *const &p1, const char *const &p2) {
    return strcmp(p1, p2);
}

// 类模版特例化
// 将标准库hash模版定义一个特例化版本,将sale_item保存在无序容器中.
// 打开命名空间,以特例化std::hash
namespace std {
template <>
struct std::hash<Sales_item> {
    // 用来散列一个无序容器的类型必须定义下列类型
    typedef std::size_t result_type;
    typedef Sales_item argument_type; // 默认情况下,此类型需要==
    std::size_t operator()(const Sales_item &s) const;
    // 我们的类使用合成的拷贝控制成员和默认构造函数
};

// hash交给标准库,将三个值的hash值进行异或得到整个对象的hash值
std::size_t std::hash<Sales_item>::operator()(const Sales_item &s) const {
    return std::hash<std::string>()(s.bookNo)
           ^ std::hash<unsigned>()(s.units_sold)
           ^ std::hash<double>()(s.revenue);
}

} // namespace std
// 关闭std命名空间,注意: 右花括号之后没有分号

#endif