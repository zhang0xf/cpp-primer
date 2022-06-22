#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// 统计成绩

int main()
{
    vector<unsigned> scores(11, 0); // 值初始化:11个分数段,全部初始化为0,11由来:100/10 = 10
    unsigned grade;
    while (cin >> grade)
    {
        if (grade <= 100)
        {
            ++scores[grade / 10]; // 将对应分数段的计数+1
        }
    }

    return 0;
}