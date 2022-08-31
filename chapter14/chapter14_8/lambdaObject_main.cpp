#include <algorithm>
#include <vector>
#include "lambdaObject.h"

int main() {
    std::vector<std::string> svec;
    svec = {"zhangfei", "hello world", "test"};

    // 使用函数对象
    std::stable_sort(svec.begin(), svec.end(), ShorterString());

    // 使用lambda表达式
    std::stable_sort(svec.begin(), svec.end(), [](const std::string &s1, const std::string &s2) {
        return s1.size() < s2.size();
    });

    return 0;
}