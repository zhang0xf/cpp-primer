#include <iostream>

using std::cin;
// using namespace std;
// 注意:头文件不应该包含using申明！

int main()
{
    int i;
    cin >> i;
    // cout << i; // 没有对应的using申明
    std::cout << i;

    return 0;
}