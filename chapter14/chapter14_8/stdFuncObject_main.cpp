#include <functional>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#include "printString.h"

// 标准库定义的一些函数对象

int main() {
    std::plus<int> intAdd;      // 可执行int加法的函数对
    std::negate<int> intNegate; // 可对int值取反的函数对象

    // 使用intAdd::operator(int, int)求10、20的和
    int sum = intAdd(10, 20);
    std::cout << sum << std::endl;

    sum = intNegate(intAdd(10, 20));
    std::cout << sum << std::endl;

    sum = intAdd(10, intNegate(10));
    std::cout << sum << std::endl;

    // 在算法中使用标准库函数对象
    std::vector<std::string> words;
    words = {"zhangfei", "hello world", "test"};
    // 排序
    std::sort(words.begin(), words.end(), std::greater<std::string>());
    // 打印
    std::for_each(words.begin(), words.end(), PrintString(std::cout, '\n'));

    std::sort(words.begin(), words.end(), std::less<std::string>());
    std::for_each(words.begin(), words.end(), PrintString(std::cout, '\n'));

    return 0;
}