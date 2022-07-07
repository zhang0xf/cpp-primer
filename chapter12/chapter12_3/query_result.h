#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H

#include <string>
#include <memory>
#include <vector>
#include <set>
#include <iostream>

class QueryResult;

std::ostream &print(std::ostream &, const QueryResult &);

class QueryResult
{
    friend std::ostream &print(std::ostream &, const QueryResult &);

public:
    using line_no = std::vector<std::string>::size_type;
    QueryResult(std::string, std::shared_ptr<std::set<line_no>>, std::shared_ptr<std::vector<std::string>>);

private:
    std::string sought;                             // 查询单词
    std::shared_ptr<std::set<line_no>> lines;       // 出现的行号
    std::shared_ptr<std::vector<std::string>> file; // 输入文件
};

#endif