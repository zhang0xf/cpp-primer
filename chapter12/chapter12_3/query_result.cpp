#include "./query_result.h"

QueryResult::QueryResult(std::string s,
                         std::shared_ptr<std::set<line_no>> p,
                         std::shared_ptr<std::vector<std::string>> f) : sought(s), lines(p), file(f)
{
}

std::ostream &print(std::ostream &os, const QueryResult &qr)
{
    // 如果找到了单词,打印出现次数和所有出现的位置
    os << qr.sought << " occurs " << qr.lines->size() << " times" << std::endl;

    for (auto num : *(qr.lines)) // 对set中每个单词
    {
        // 避免行号从0开始给用户带来困惑
        os << "\t(line " << num + 1 << ")" << *(qr.file->begin() + num) << std::endl;
    }

    return os;
}