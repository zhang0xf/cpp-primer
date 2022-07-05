#include <fstream>
#include <map>
#include <string>
#include <stdexcept>
#include <sstream> // istringstream头文件按
#include <iostream>

using std::ifstream;
using std::istringstream;
using std::map;
using std::ofstream;
using std::string;

// 建立转换映射
map<string, string> buildMap(ifstream &map_file)
{
    map<string, string> trans_map; // 保存转换规则
    string key;                    // 需要转换的单词
    string value;                  // 转换后的内容

    // 读取第一个单词存入key中，行中剩余内容存入value
    while (map_file >> key && getline(map_file, value))
    {
        if (value.size() > 1) // 检查是否有转换规则
        {
            trans_map[key] = value.substr(1); // 跳过前导空格
        }
        else
        {
            throw std::runtime_error("No rule for " + key);
        }
    }
    return trans_map;
}

const string &transform(const string &s, const map<string, string> &m)
{
    // 实际的转换工作,此部分是程序的核心
    auto map_it = m.find(s);
    // 如果单词在转换规则map中
    if (map_it != m.cend())
    {
        return map_it->second; // 使用替换字符串
    }
    else
    {
        return s; // 返回原字符串
    }
}

//@map_file: 绑定到单词转换文件
//@input: 绑定到我们要转换的文本文件
void word_transform(ifstream &map_file, ifstream &input)
{
    auto trans_map = buildMap(map_file); // 保存转换规则
    string text;

    while (getline(input, text))
    {
        istringstream stream(text); // 读取每个单词
        string word;
        bool first_word = true;
        while (stream >> word)
        {
            if (first_word)
            {
                first_word = false;
            }
            else
            {
                std::cout << " "; // 在单词间打印一个空格
            }

            std::cout << transform(word, trans_map); // 打印输出
        }
        std::cout << std::endl; // 一行结束
    }
}

int main()
{
    string rule_filename("/home/zhangfei/cpp/cpp-primer/data/map_transform.txt");
    string input_filename("/home/zhangfei/cpp/cpp-primer/data/map_transform_input.txt");

    ifstream rule(rule_filename);
    ifstream input(input_filename);

    word_transform(rule, input);

    return 0;
}