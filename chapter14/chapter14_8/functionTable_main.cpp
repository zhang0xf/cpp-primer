#include <functional>
#include <iostream>
#include "functionTable.h"

int main() {
    // 将add函数加入binops
    binops.insert({"+", add});

    binops.clear();

    // mod不是一个函数指针(需要借助function类型)
    // 申明一个function类型 : function<调用形式>
    std::function<int(int, int)> f1 = add;
    std::function<int(int, int)> f2 = divide();
    std::function<int(int, int)> f3 = [](int i, int j) {
        return i * j;
    };
    std::function<int(int, int)> f4 = mod;

    // 调用
    std::cout << f1(4, 2) << std::endl;
    std::cout << f2(4, 2) << std::endl;
    std::cout << f3(4, 2) << std::endl;
    std::cout << f4(4, 2) << std::endl;

    // 重新定义map
    std::map<std::string, std::function<int(int, int)>> binopsPro;

    binopsPro.insert(std::make_pair<std::string, std::function<int(int, int)>>("+", add));
    binopsPro.insert({"-", std::minus<int>()});
    binopsPro.insert({"/", divide()});
    binopsPro.insert({"*", [](int i, int j) { return i * j; }});
    binopsPro.insert({"%", mod});

    // 函数调用
    std::cout << binopsPro["+"](10, 5) << std::endl;
    std::cout << binopsPro["-"](10, 5) << std::endl;
    std::cout << binopsPro["*"](10, 5) << std::endl;
    std::cout << binopsPro["/"](10, 5) << std::endl;
    std::cout << binopsPro["%"](10, 5) << std::endl;

    return 0;
}