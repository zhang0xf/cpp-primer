#include "printString.h"

void PrintString::operator()(const std::string &s) const {
    os << s << sep;
}