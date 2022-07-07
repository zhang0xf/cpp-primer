#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H

#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <set>

#include "./query_result.h"

class QueryResult;

class TextQuery
{
    friend QueryResult;

public:
    using line_no = std::vector<std::string>::size_type;

    TextQuery(std::ifstream &infile);
    QueryResult query(const std::string &s) const;

private:
    std::shared_ptr<std::vector<std::string>> file;               // 输入文件(每个vector的元素存储文件的一行内容,且需要与QueryResult共享)
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm; // 每个单词到它所在行号的集合的映射(需要与QueryResult共享)
};

#endif