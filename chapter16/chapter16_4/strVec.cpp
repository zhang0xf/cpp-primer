#include <utility>
#include <iostream>
#include "strVec.h"

StrVec::StrVec(const StrVec &sv) {
    // 调用alloc_n_copy分配空间,以容纳与sv中一样多的元素
    auto newdata = alloc_n_copy(sv.begin(), sv.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::StrVec(StrVec &&sv) noexcept :
    // 成员初始化器,接管s中的资源
    elements(sv.elements), first_free(sv.first_free), cap(sv.cap) {
    // 令s进入这样的状态:对其运行析构函数是安全的
    sv.elements = sv.first_free = sv.cap = nullptr;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept {
    // 直接检测自赋值
    if (this != &rhs) {
        free();                  // 释放已有元素
        elements = rhs.elements; // 从rhs接管资源
        first_free = rhs.first_free;
        cap = rhs.cap;
        // 将rhs置于可析构的状态
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

StrVec::~StrVec() {
    // 析构函数调用free
    free();
}

// 拷贝赋值操作
StrVec &StrVec::operator=(const StrVec &rhs) {
    // 调用alloc_n_copy分配内存,大小与rhs中元素占用的空间一样多
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free(); // 销毁原内存中的元素,并释放这块内存!
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

// 重载(支持初始化列表)
StrVec &StrVec::operator=(std::initializer_list<std::string> li) {
    // 调用alloc_n_copy分配内存,大小与rhs中元素占用的空间一样多
    auto data = alloc_n_copy(li.begin(), li.end());
    free();                // 销毁原内存中的元素,并释放这块内存!
    elements = data.first; // 更新数据成员,使其指向新空间
    first_free = cap = data.second;
    return *this;
}

// 重载不等运算符
bool StrVec::operator!=(StrVec &rhs) const {
    if (this->elements == rhs.elements && this->first_free == rhs.first_free && this->cap == rhs.cap) {
        return true;
    }
    return false;
}

// 非常量版本下标运算
std::string &StrVec::operator[](std::size_t n) {
    return elements[n];
}

// 常量版本下标运算
const std::string &StrVec::operator[](std::size_t n) const {
    return elements[n];
}

void StrVec::check_n_alloc() {
    if (size() == capacity()) {
        reallocate();
    }
}

// 避免string的拷贝(对于reallocate场景,拷贝之后string的用户还是原来那一个)
// string的移动构造函数
// void StrVec::reallocate() {
//     // 我们将分配当前大小2倍的内存空间
//     auto newcapacity = size() ? 2 * size() : 1;
//     // 分配新内存
//     auto newdata = alloc.allocate(newcapacity);
//     // 将数据从旧内存移动到新内存
//     auto dest = newdata;  // 指向数组中下一个空闲位置
//     auto elem = elements; // 指向旧数组中下一个元素
//     for (size_t i = 0; i != size(); ++i) {
//         alloc.construct(dest++, std::move(*elem++));
//     }
//     // 一旦我们移动完所有元素,就释放旧内存空间
//     free();
//     // 更新我们的数据结构,执行新元素
//     elements = newdata;
//     first_free = dest;
//     cap = elements + newcapacity;
// }

// 使用移动迭代器(上文过程等价方法)
void StrVec::reallocate() {
    auto newcapacity = size() ? 2 * size() : 1;
    auto first = alloc.allocate(newcapacity);
    // 移动元素
    auto last = std::uninitialized_copy(std::make_move_iterator(begin()), std::make_move_iterator(end()), first);
    // 释放旧空间
    free();

    // 更新指针
    elements = first;
    first_free = last;
    cap = elements + newcapacity;
}

std::pair<std::string *, std::string *>
StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
    // 分配空间保存给定范围的元素
    auto data = alloc.allocate(e - b);
    // 初始化并返回一个pair,该pair由data和uninitialized_copy的返回值构成
    return {data, std::uninitialized_copy(b, e, data)};
}

void StrVec::push_back(const std::string &str) {
    // 确保有空间容纳新元素
    check_n_alloc();

    // first_free指向的元素中构造s的副本
    alloc.construct(first_free, str);
}

// 实参类型决定了新元素是拷贝还是移动
void StrVec::push_back(std::string &&str) {
    check_n_alloc();
    alloc.construct(first_free, std::move(str)); // 会使用string的移动构造函数来构造新元素
}

void StrVec::free() {
    // 不能传递给deallocate一个空指针,如果elements为0,函数什么也不做。
    if (elements) {
        for (auto p = first_free; p != elements; /* 空 */) {
            // 逆序销毁元素
            alloc.destroy(--p);
        }
        // 释放StrVec对象空间
        alloc.deallocate(elements, cap - elements);
    }
}

size_t StrVec::size() const {
    return first_free - elements;
}

size_t StrVec::capacity() const {
    return cap - elements;
}

std::string *StrVec::begin() const {
    return elements;
}

std::string *StrVec::end() const {
    return first_free;
}