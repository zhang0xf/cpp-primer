#ifndef TEMPLETE_H
#define TEMPLETE_H

#include <algorithm>

template <typename T>
int compare(const T &v1, const T &v2) {
    if (v1 < v2) {
        return -1;
    }
    if (v2 > v1) {
        return 1;
    }
    return 0;
}

// 模版类型参数
template <typename T>
T Func(T *p) {
    T tmp = *p;
    return tmp;
}

//非类型模版参数
template <unsigned N, unsigned M>
int compare(const char (&p)[N], const char (&q)[M]) { // 字符串数组的引用
    return strcmp(p, q);
}

// inline
template <typename T>
inline T min(const T &, const T &) {
}

// 增加类型无关和可移植性(注意: 只使用了"<")
template <typename T>
int compare_pro(const T &v1, const T &v2) {
    if (std::less<T>()(v1, v2)) {
        return -1;
    }

    if (std::less<T>()(v2, v1)) {
        return 1;
    }

    return 0;
}

// 模版与友元
// 前置申明,在Blob中申明友元所需要的
template <typename>
class BlobPtr;

template <typename>
class Blob; // 相等运算符友元函数==中的参数所需要

// 友元函数申明
template <typename T>
bool operator==(const Blob<T> &, const Blob<T> &);

// 类模版(chapter12_1)
// 不再针对string,模版会提供对元素的共享访问能力
template <typename T>
class Blob {
    // 友元申明
    // 每个Blob实例类将访问权限授予用相同类型实例化的BlobPtr和相等运算符.
    friend class BlobPtr<T>;
    friend bool operator==<T>(const Blob<T> &, const Blob<T> &);

public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type; // 注意typename关键字!!!

    // 构造函数
    Blob();
    Blob(std::initializer_list<T> li);

    // Blob中的元素数目
    size_type size() const { // 类内定义: 默认内联
        return data->size();
    }
    bool empty() {
        return data->empty();
    }

    // 添加元素
    void push_back(const T &t) {
        data->push_back(t);
    }

    // 移动版本
    void push_back(T &&t) {
        data->push_back(std::move(t));
    }

    // 删除元素
    void pop_back();

    // 元素访问
    T &front();
    T &back();

    // 下标运算符
    T &operator[](std::size_t i);

private:
    std::shared_ptr<std::vector<T>> data;
    // 若data[i]无效,则抛出msg
    void check(size_type i, const std::string &msg) const;
};

// 类外定义类模版的成员函数
template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const {
    if (i >= data->size()) {
        throw std::out_of_range(msg);
    }
}

// 构造函数
template <typename T>
Blob<T>::Blob() :
    data(std::make_shared<std::vector<T>>()) {
}

template <typename T>
Blob<T>::Blob(std::initializer_list<T> li) :
    data(std::make_shared<std::vector<T>>(li)) {
}

// 元素访问
template <typename T>
T &Blob<T>::front() {
    check(0, "back on empty Blob");
    return data->front();
}

template <typename T>
T &Blob<T>::back() {
    check(0, "back on empty Blob");
    return data->back();
}

// 下标运算
template <typename T>
T &Blob<T>::operator[](std::size_t i) {
    check(i, "subsript out of range");
    return (*data)[i];
}

// 删除元素
template <typename T>
void Blob<T>::pop_back() {
    check(0, "back on empty Blob");
    return data->pop_back();
}

// 若试图访问一个不存在的元素,BlobPtr将抛出一个异常
template <typename T>
class BlobPtr {
public:
    BlobPtr() :
        curr(0) {
    }
    BlobPtr(Blob<T> &a, std::size_t sz = 0) :
        wptr(a.data), curr(sz) {
    }

    T &operator*() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }

    // 递增和递减
    // 编译器处理模版自身引用会特殊处理,不需要BlobPtr<T>
    BlobPtr &operator++(); // 前置
    BlobPtr &operator--();
    BlobPtr operator++(int); // 后置

private:
    std::shared_ptr<std::vector<T>>
    check(std::size_t, const std::string &) const;
    // 保存一个weak_ptr意味着底层vector可能会被销毁
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};

// 在类模版外使用类模版名
// 此时不在类模版的作用域中
template <typename T>
BlobPtr<T> &BlobPtr<T>::operator++() {
    check(curr, "increment past end of strBlobPtr");
    ++curr;
    return *this;
}

// 模版类型别名
template <typename T>
using twin = std::pair<T, T>;

// 固定一个或多个参数
template <typename T>
using partNo = std::pair<T, unsigned>;

// 模版和静态成员
template <typename T>
class Foo {
public:
    static std::size_t count() {
        return ctr;
    }

private:
    static std::size_t ctr;
};

template <typename T>
std::size_t Foo<T>::ctr = 0; // 定义并初始化ctr

// 默认参数
template <typename T, typename F = std::less<T>>
int compare_pro2(const T &v1, const T &v2, F f = F()) { // 使用了类型F(标准库less对象)的默认初始化
    if (f(v1, v2)) {
        return -1;
    }

    if (f(v2, v1)) {
        return 1;
    }

    return 0;
}

// 模版默认实参
template <typename T = int> // T默认是int
class Numbers {
public:
    Numbers(T v = 0) :
        val(v) {
    }

private:
    T val;
};

// 成员模版

// 普通类的成员函数模版
class DebugDelete {
public:
    DebugDelete(std::ostream &s = std::cerr) :
        os(s) {
    }
    // 与任何函数模版相同,T的类型由编译器推断
    template <typename T>
    void operator()(T *p) const {
        os << "deleting unique ptr" << std::endl;
        delete p;
    }

private:
    std::ostream &os;
};

// 类模版的成员函数模版
template <typename T>
class Blob_pro {
public:
    // 构造函数模版
    template <typename It>
    Blob_pro(It begin, It end); // 由两个迭代器指定的范围的元素构建对象
private:
    std::shared_ptr<std::vector<T>> data;
};

// 类外实现构造函数的定义
template <typename T>  // 类的类型参数
template <typename It> // 构造函数的类型参数
Blob_pro<T>::Blob_pro(It begin, It end) :
    data(std::make_shared<std::vector<T>>(begin, end)) {
}

// 控制实例化(多个文件有可能实例化出相同的类)

#endif