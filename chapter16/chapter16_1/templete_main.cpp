#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "templete.h"
#include "sale_items.h"

int main() {
    std::vector<int> vec1{1, 2, 3}, vec2{4, 5, 6};

    // 编译器推断模版实参
    std::cout << compare(1, 2) << std::endl;
    std::cout << compare(vec1, vec2) << std::endl;

    std::cout << compare("hello", "zhangfei") << std::endl;

    // 实例化Blob模版
    Blob<int> ia;
    Blob<int> ia2 = {1, 2, 3, 4, 5};
    Blob<std::string> names;
    Blob<double> prices;

    ia2.pop_back();
    ia2.push_back(10);
    std::cout << ia2.front() << std::endl;
    std::cout << ia2.back() << std::endl;
    std::cout << ia2[3] << std::endl;

    twin<int> win_loss;
    win_loss = std::make_pair<int, int>(10, 12);

    twin<double> area(std::make_pair<double, double>(3.14, 3.14));
    std::cout << area.first << std::endl;

    partNo<std::string> books{"hello", 10};
    std::cout << books.second << std::endl;

    Foo<int> fi;                 // 实例化Foo<int>类和static数据成员ctr(static成员函数只有使用时才实例化)
    auto ct = Foo<int>::count(); // 实例化Foo<int>::count
    ct = fi.count();             // 使用Foo<int>::count
    // ct = Foo::count(); // error
    std::cout << ct << std::endl;

    // 默认实参
    Sales_item item1;
    Sales_item item2;
    bool i = compare_pro2(1, 20); // 调用默认函数的实参,此例中: T = int, 即less<int>
    bool j = compare_pro2(item1, item2, compareIsbn);
    std::cout << i << std::endl;
    std::cout << j << std::endl;

    // 默认模版实参
    Numbers<long double> lost_of_precisions;
    Numbers<> average_precision; // 使用了模版的默认实参int

    // 普通类成员函数模版
    double *p = new double;
    DebugDelete d; // 可像delete表达式一样使用的对象
    d(p);          // 调用DebugDelete::operator()(double*),释放p
    int *ip = new int;
    // 在一个临时的对象上调用operator()(int*)
    DebugDelete()(ip); // 注意括号

    // 将DebugDelete用作unique_ptr的删除器
    // 重载unique_ptr的删除器(在尖括号中给出),unique_ptr的析构函数会调用DebugDelete的调用运算符

    // 销毁p指向的对象
    // 实例化: DebugDelete::operator()<int>(int*)
    std::unique_ptr<int, DebugDelete> unip(new int, DebugDelete());

    // 销毁sp指向的对象
    // 实例化: DebugDelete::operator()<string>(string*)
    std::unique_ptr<std::string, DebugDelete> unisp(new std::string, DebugDelete());

    // 实例化类模版的成员模版(编译器推断)
    int ia3[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<long> vil = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<const char *> w = {"now", "is", "the", "time"};
    // 实例化Blob_pro<int>类,实例化接受两个int*类型的构造函数
    Blob_pro<int> b1(std::begin(ia3), std::end(ia3));
    // 实例化Blob_pro<int>类,实例化接受两个vector<long>::iterator类型的构造函数
    Blob_pro<int> b2(vil.begin(), vil.end());
    // 实例化Blob_pro<int>类,实例化接受两个list<const char*>::iterator类型的构造函数
    Blob_pro<std::string> b3(w.begin(), w.end());

    return 0;
}