#ifndef STRBLOB_H
#define STRBLOB_H

#include <vector>
#include <string>
#include <memory>

class StrBlobPtr;

class StrBlob {
    friend class StrBlobPtr; // 指定友元(为了获取data)
public:
    typedef std::vector<std::string>::size_type size_type;

    StrBlob();
    StrBlob(std::initializer_list<std::string> li);

    size_type size() const {
        return data->size();
    }
    bool empty() {
        return data->empty();
    }

    // 添加和删除元素
    void push_back(const std::string &t) {
        data->push_back(t);
    }
    void pop_back();

    // 元素访问
    std::string &front();
    std::string &back();

    // 拷贝、赋值和销毁
    // 使用默认版本的拷贝、赋值和销毁,因为StrBlob类只有一个数据成员shared_ptr.

public:
    StrBlobPtr begin(); // 最好的方式:遵循c++标准,将所有的实现都放在.cpp中,减少"invalid use of incomplete type"的编译错误!
    StrBlobPtr end();

private:
    std::shared_ptr<std::vector<std::string>> data; // 指向vector的智能指针
    // 如果data[i]不合法,则抛出一个异常
    void check(size_type i, const std::string &msg) const; // 元素访问成员函数需要先检查
};

#endif