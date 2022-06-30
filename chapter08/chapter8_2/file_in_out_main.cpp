#include <fstream>
#include <string>

#include "sale_data.h"

// run : ./bin/file_in_out_main ./data/book_sell.txt

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Not enough params!" << std::endl;
        return -1;
    }

    std::string fileName(argv[1]);

    std::ifstream input(fileName); // 打开销售记录文件
    if (!input)
    {
        std::cout << "open file : " << fileName << " fail!" << std::endl;
    }

    std::ofstream output;
    output.open(fileName + ".copy"); // 模式:(隐含输出和截断)
    // output.open(fileName + ".copy", std::ofstream::out);                       // 模式:输出(隐含截断文件)
    // output.open(fileName + ".copy", std::ofstream::out | std::ostream::trunc); // 模式:输出和截断
    // output.open(fileName + ".copy", std::ofstream::app);                       // 模式:追加(隐含输出文件)
    // output.open(fileName + ".copy", std::ofstream::out | std::ofstream::app);  // 模式:输出和追加
    if (!output) // 检查是否打开成功
    {
        std::cout << "open file : " << fileName << ".copy"
                  << " fail!" << std::endl;
        return -1;
    }

    Sales_Data total; // 保存销售总额的变量
    if (read(input, total))
    {
        Sales_Data trans;
        while (read(input, trans)) // 读取剩余记录
        {
            if (total.isbn() == trans.isbn())
            {
                total.combine(trans); // 更新销售总额
            }
            else
            {
                print(output, total) << std::endl; // 打印结果
                total = trans;                     // 处理下一本
            }
        }
        print(output, total) << std::endl; // 打印最后一本书的销售额
    }
    else
    {
        std::cerr << "NO Data?" << std::endl;
    }

    // 关闭文件
    input.close();
    output.close();

    return 0;
}