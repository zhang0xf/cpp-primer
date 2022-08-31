#include "lambdaObject.h"

bool ShorterString::operator()(const std::string &s1, const std::string &s2) const {
    return s1.size() < s2.size();
}