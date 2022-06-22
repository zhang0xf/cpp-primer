#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    string word;

    vector<string> text; // 空vector对象(vector可以高效增长)
    while (cin >> word)
    {
        text.push_back(word); // 将word添加到text后面
    }

    return 0;
}