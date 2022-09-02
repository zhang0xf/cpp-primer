#include "access_control.h"

int main() {
    // 派生类用户
    Pub_Dery d1;
    Priv_Dery d2;
    d1.pub_mem(); // 正确: pub_mem在派生类中是public的
    // d2.pub_mem(); // 错误: pub_mem在派生类中是private的
    d2.g();

    Derived du;
    du.size();
    return 0;
}