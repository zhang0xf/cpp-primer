#ifndef LAMBDA_OBJECT_H
#define LAMBDA_OBJECT_H

#include <string>

// lambda是函数对象!!!

class ShorterString {
public:
    bool operator()(const std::string &s1, const std::string &s2) const;
};

#endif