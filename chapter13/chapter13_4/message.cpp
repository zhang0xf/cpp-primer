#include <iostream>
#include <utility>
#include "./message.h"
#include "./floder.h"

void Message::save(Floder &f) {
    floders.insert(&f); // 将给定的floder添加到我们的floder列表中
    f.addMsg(this);     // 将本message添加到f的message集合中
}

void Message::remove(Floder &f) {
    floders.erase(&f);
    // f.removeMsg(this);
}

// 拷贝构造函数拷贝给定对象的数据成员
Message::Message(const Message &msg) :
    contents(msg.contents), floders(msg.floders) // 相同的message应该出现在相同的地方
{
    add_to_floders(msg);
}

// 拷贝赋值操作
Message &Message::operator=(const Message &msg) {
    // 通过先删除指针,再插入它们来处理自赋值的情况
    remove_from_floders(); // 更新已有的floder
    this->contents = msg.contents;
    this->floders = msg.floders; // 拷贝floder指针
    add_to_floders(msg);         // 将本message添加到floders中
    return *this;
}

// 析构函数
Message::~Message() {
    std::cout << "message realease " << std::endl;
    remove_from_floders();
}

// 移动构造函数
Message::Message(Message &&msg) :
    contents(std::move(msg.contents)) {
    move_Floders(&msg);
}

// 移动赋值运算符
Message &Message::operator=(Message &&rhs) {
    // 直接检查自赋值的情况
    if (this != &rhs) {
        remove_from_floders();
        contents = std::move(rhs.contents); // 移动赋值运算符
        move_Floders(&rhs);                 // 重置Floders指向本Message
    }
    return *this;
}

void Message::add_to_floders(const Message &msg) {
    for (auto f : msg.floders) // 对每个包含msg的floder
    {
        f->addMsg(this);
    }
}

void Message::remove_from_floders() {
    for (auto f : floders) // 对floder中的每个指针
    {
        f->removeMsg(this);
    }
}

// 公共操作:更新floder指针
void Message::move_Floders(Message *msg) {
    // std::move获得绑定到左值上的右值引用
    floders = std::move(msg->floders); // 使用set的移动赋值运算符
    for (auto f : floders) {           // 对每个Floder
        f->removeMsg(msg);             // 从Floder中删除旧Message
        f->addMsg(this);               // 将本Message添加到Floder中
    }
    msg->floders.clear(); // 确保销毁msg是无害的
}

void swap(Message &lhs, Message &rhs) {
    using std::swap; // 在本例中严格来说并不需要,但这是一个好习惯
    // 将每个消息的指针从它(原来)的floder中删除
    for (auto f : lhs.floders) {
        f->removeMsg(&lhs);
    }
    for (auto f : rhs.floders) {
        f->removeMsg(&rhs);
    }
    // 交换contents和floders
    swap(lhs.contents, rhs.contents); // 调用swap(set&, set&)
    swap(lhs.floders, rhs.floders);   // 调用swap(string&, string&)

    // 添加message到新的floder
    for (auto f : lhs.floders) {
        f->addMsg(&lhs);
    }
    for (auto f : rhs.floders) {
        f->addMsg(&rhs);
    }
}