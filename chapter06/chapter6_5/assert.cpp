#include <iostream>
#include <string>
#include <cassert> // assert

// 编译选项: cc -D NDEBUG main.c 表示关闭调试状态

using std::cerr;
using std::cout;
using std::endl;
using std::string;

void print_word(const string &word, string::size_type size)
{
    assert(word.size() > 10); // 使用assert编写调试代码:要求word长度大于10,否则终止程序并给出调试信息
    cout << word << " size is " << size << endl;
    return;
}

// assert依赖于NDEBUG预处理变量的状态,如果定义了NDEBUG,则assert什么也不做.
void print_word(const string &word)
{
#ifndef NDEBUG                                                     // 使用NDEBUG编写自定义条件调试代码
    cerr << __func__ << ": array size is " << word.size() << endl; // __func__:输出当前调试函数的名字
    // 使用更多的宏,输出更丰富的调试信息:
    cerr << "Error : " << __FILE__ << " : in function " << __func__
         << " at line " << __LINE__ << endl
         << "       compiled on " << __DATE__
         << " at " << __TIME__ << endl
         << "       word read was \"" << word
         << "\" : Length too short" << endl;
#endif

    return;
}

int main()
{
    string word("hello world");
    string word2("zhangfei");

    print_word(word, word.size());
    print_word(word);

    print_word(word2, word.size());
    print_word(word2);

    return 0;
}