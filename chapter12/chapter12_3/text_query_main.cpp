#include <string>

#include "./text_query.h"

// ./bin/text_query_main ./data/text_query.txt

void runQueries(std::ifstream &infile)
{
    // infile指向我们需要处理的文件
    TextQuery tq(infile); // 保存文件.并建立查询map

    // 与用户交互:提示用户输入要查询的单词,完成查询并打印结果
    while (true)
    {
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q")
        {
            break;
        }
        // 指向查询并打印结果
        print(std::cout, tq.query(s)) << std::endl;
    }
}

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        std::ifstream file;
        file.open(argv[1]);
        if (!file)
        {
            std::cout << " open file error " << std::endl;
        }

        runQueries(file);
    }

    return 0;
}