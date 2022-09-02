#include "access_control.h"

// 正确: clobber能访问Sneaky对象的private和protected成员
void clobber(Sneaky &s) {
    s.j = s.prot_mem = 0;
}

// 错误: clobber不能访问Base的protected成员(Sneaky成员或友元只能通过Sneaky对象访问Base的受保护成员)
void clobber(Base &b) {
    // b.port_name = 0;
    b.pub_mem();
}