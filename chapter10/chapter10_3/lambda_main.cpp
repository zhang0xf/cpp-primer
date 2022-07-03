#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>

using std::string;
using std::vector;

void print(vector<string> vec)
{
    for (const auto &it : vec)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
}

std::ostream &print2(std::ostream &os, const string &s, char c)
{
    return os << s << c;
}

bool check_size(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}
auto check5 = std::bind(check_size, std::placeholders::_1, 5); // _1表示占位符:_1表示check5的第一个参数,_2表示check5的第二个参数,以此类推.

bool isShorter(const string &s1, const string &s2) // 二元谓词!
{
    return s1.size() < s2.size();
}

void elimDups(vector<string> &words)
{
    std::sort(words.begin(), words.end());
    auto end_unique = std::unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

void biggies1(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    std::stable_sort(words.begin(), words.end(), isShorter);

    // 获取一个迭代器,指向第一个满足size() >= sz的元素
    auto wc = std::find_if(words.begin(), words.end(), [sz](const string &word)
                           { return word.size() >= sz; }); // find_if只接受一元谓词,[]捕获列表以"值捕获"方式捕获局部变量sz.find_if返回一个迭代器.

    // 计算满足size() >= sz的元素数目
    auto count = words.end() - wc;
    std::cout << " 大于或等于 " << sz << " 的单词个数: " << count << std::endl;

    // 打印长度大于等于给定值的单词,每个单词后接一个空格
    // std::cout变量可以直接使用!
    std::for_each(wc, words.end(), [](const string &s)
                  { std::cout << s << " "; });
    std::cout << std::endl;
}

void biggies2(vector<string> &words, vector<string>::size_type sz, std::ostream &os = std::cout, char ch = ' ')
{
    elimDups(words);
    std::stable_sort(words.begin(), words.end(), isShorter);

    auto wc = std::find_if(words.begin(), words.end(), [sz](const string &word)
                           { return word.size() >= sz; });

    auto count = words.end() - wc;
    std::cout << " 大于或等于 " << sz << " 的单词个数: " << count << std::endl;

    std::for_each(wc, words.end(), [&os, ch](const string &s)
                  { os << s << ch; }); // 引用捕获,有时候是必要的!
    std::cout << std::endl;
}

void biggies3(vector<string> &words, vector<string>::size_type sz, std::ostream &os = std::cout, char ch = ' ')
{
    elimDups(words);
    std::stable_sort(words.begin(), words.end(), isShorter);

    auto wc = std::find_if(words.begin(), words.end(), [sz](const string &word)
                           { return word.size() >= sz; });

    auto count = words.end() - wc;
    std::cout << " 大于或等于 " << sz << " 的单词个数: " << count << std::endl;

    std::for_each(wc, words.end(), [&, ch](const string &s)
                  { os << s << ch; }); // os隐式捕获,引用捕获;ch显示捕获,值捕获
    std::cout << std::endl;
}

void biggies4(vector<string> &words, vector<string>::size_type sz, std::ostream &os = std::cout, char ch = ' ')
{
    elimDups(words);
    std::stable_sort(words.begin(), words.end(), isShorter);

    auto wc = std::find_if(words.begin(), words.end(), [sz](const string &word)
                           { return word.size() >= sz; });

    auto count = words.end() - wc;
    std::cout << " 大于或等于 " << sz << " 的单词个数: " << count << std::endl;

    std::for_each(wc, words.end(), [=, &os](const string &s)
                  { os << s << ch; }); // ch隐式捕获,值捕获;os显示捕获,引用捕获
    std::cout << std::endl;
}

void biggies5(vector<string> &words, vector<string>::size_type sz, std::ostream &os = std::cout, char ch = ' ')
{
    elimDups(words);
    std::stable_sort(words.begin(), words.end(), isShorter);

    auto wc = std::find_if(words.begin(), words.end(), std::bind(check_size, std::placeholders::_1, sz)); // 使用bind替换lambda表达式,目的:避免某些场景下，重复编写相同的lambda表达式!!!

    auto count = words.end() - wc;
    std::cout << " 大于或等于 " << sz << " 的单词个数: " << count << std::endl;

    std::for_each(wc, words.end(), [&os, ch](const string &s)
                  { os << s << ch; });
    std::cout << std::endl;
}

void biggies6(vector<string> &words, vector<string>::size_type sz, std::ostream &os = std::cout, char ch = ' ')
{
    elimDups(words);
    std::stable_sort(words.begin(), words.end(), isShorter);

    auto wc = std::find_if(words.begin(), words.end(), std::bind(check_size, std::placeholders::_1, sz));

    auto count = words.end() - wc;
    std::cout << " 大于或等于 " << sz << " 的单词个数: " << count << std::endl;

    std::for_each(wc, words.end(), std::bind(print2, std::ref(os), std::placeholders::_1, ch)); // ref:绑定引用参数(有的参数必须使用引用传递), for_each将string作为bind生成的"newCallable"的参数
    std::cout << std::endl;
}

int main()
{
    vector<string>
        words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};

    elimDups(words);
    std::stable_sort(words.begin(), words.end(), [](const string &a, const string &b)
                     { return a.size() < b.size(); }); // lambda表达式:[]捕获*它所在函数中*的局部变量(可以是列表)
    print(words);

    // lambda[]捕获列表(值捕获方式举例)
    biggies1(words, 4);
    biggies1(words, 5);

    // lambda[]引用捕获
    biggies2(words, 5);
    biggies2(words, 5, std::cout, ' '); // os可以是文件流

    // lambda[]隐式捕获，多种捕获方式混用
    biggies3(words, 5);
    biggies4(words, 5);

    // bind():用来解决编写许多相同lambda表达式的问题场景
    if (check5("turtle"))
    {
        std::cout << "turtle 的长度大于5! " << std::endl;
    }
    biggies5(words, 5);

    // 绑定引用参数
    biggies6(words, 5);

    return 0;
}