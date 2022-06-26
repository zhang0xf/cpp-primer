#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

char &get_val(string &s, string::size_type ix)
{
    return s[ix];
}

int main()
{
    string s("a value");
    cout << s << endl;
    get_val(s, 0) = 'A'; // 返回左值引用
    cout << s << endl;
    return 0;
}