#ifndef STRVEC_H
#define STRVEC_H

#include <memory>
#include <string>

// 类似vector内存分配策略的简化实现

// 优先使用nullptr初始化指针,而非NULL(0)

class StrVec {
public:
    // 构造函数(成员进行默认的初始化)
    StrVec() :
        elements(nullptr), first_free(nullptr), cap(nullptr) {
    }
    // 拷贝构造函数
    StrVec(const StrVec &);

    // 拷贝赋值运算符
    StrVec &operator=(const StrVec &);
    // 重载拷贝赋值(支持初始化列表)
    StrVec &operator=(std::initializer_list<std::string>);

    // 移动构造函数(避免某些情况下的拷贝)
    // 参数是一个右值引用,使用&&表示右值引用(某个对象的另一个名字),与左值引用有着相反的特性.
    StrVec(StrVec &&sv) noexcept; // 移动操作不应该跑出任何异常

    // 移动赋值运算符
    StrVec &operator=(StrVec &&rhs) noexcept;

    // 不等运算符
    bool operator!=(StrVec &rhs) const;

    // 下标运算符
    std::string &operator[](std::size_t n);
    // 常量版本的下标运算符
    const std::string &operator[](std::size_t n) const;

    // 析构函数
    ~StrVec();

    // 拷贝元素
    void push_back(const std::string &);
    // 移动构造重载(右值引用参数)
    void push_back(std::string &&);

    size_t size() const;
    size_t capacity() const;
    std::string *begin() const;
    std::string *end() const;

    // ...

private:
    // static std::allocator<std::string> alloc; // 分配元素
    std::allocator<std::string> alloc;

    // 被添加元素的函数使用的函数
    void check_n_alloc();

    // 工具函数,被拷贝构造函数,赋值运算符和析构函数所使用
    std::pair<std::string *, std::string *> alloc_n_copy(const std::string *, const std::string *);
    void free();             // 销毁元素并释放内存
    void reallocate();       // 获得更多的内存并拷贝已有的元素
    std::string *elements;   // 指向数组元素的首指针
    std::string *first_free; // 指向数组第一个空闲的指针
    std::string *cap;        // 指向数组尾后位置的指针
};

#endif