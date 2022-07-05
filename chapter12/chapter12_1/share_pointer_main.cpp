#include <memory>
#include <string>
#include <vector>

using std::string;
using std::vector;

int main()
{
    // make_shared函数
    std::shared_ptr<int> p3 = std::make_shared<int>(42);
    std::shared_ptr<string> p4 = std::make_shared<string>(10, '9');
    std::shared_ptr<int> p5 = std::make_shared<int>(); // 值初始化

    auto p6 = std::make_shared<vector<string>>(); // 指向一个动态分配的空vector

    // 拷贝和赋值
    auto p = std::make_shared<int>(42); // p指向的对象只有p一个引用者
    auto q(p);                          // p和q指向相同的对象,此对象有两个引用者
    auto r = std::make_shared<int>(42); // r指向的int只有一个引用者
    r = q;                              // 给r赋值,令其指向另一个地址
                                        // 递增了q指向的对象的引用计数
                                        // 递减了r原来指向的对象的引用计数
                                        // r原来指向的对象已经没有引用者,会自动释放

    return 0;
}