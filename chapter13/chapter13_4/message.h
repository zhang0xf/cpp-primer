#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <set>

class Floder;

class Message
{
    friend class Floder;
    friend void swap(Message &, Message &);

public:
    //  floders被隐式初始化为空集合
    explicit Message(const std::string &str = "") : contents(str) {} // contents默认参数空

    // 拷贝控制成员,用来管理指向本message的指针
    Message(const Message &);            // 拷贝构造函数
    Message &operator=(const Message &); // 拷贝赋值操作
    ~Message();                          // 析构函数

    // 从给定floder中添加和删除message
    void save(Floder &);
    void remove(Floder &);

private:
    std::string contents;       // 实际消息文本
    std::set<Floder *> floders; // 包含本message的floder

    // 拷贝构造函数、拷贝赋值运算、析构函数所使用的工具函数
    // 将本message添加到指向参数的floder中
    void add_to_floders(const Message &);
    // 从floders中的每一个floder删除本message
    void remove_from_floders();
};

void swap(Message &, Message &);

#endif