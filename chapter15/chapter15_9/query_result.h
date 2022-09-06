#ifndef QUERY_RESULT_H
#define QUERY_RESULT_H

#include <string>
#include <memory>
#include <vector>
#include <set>
#include <iostream>

class QueryResult;

std::ostream &print(std::ostream &, const QueryResult &);

class QueryResult {
    friend std::ostream &print(std::ostream &, const QueryResult &);

public:
    using line_no = std::vector<std::string>::size_type;
    QueryResult(std::string, std::shared_ptr<std::set<line_no>>, std::shared_ptr<std::vector<std::string>>);

public:
    // 用于遍历行号
    std::set<line_no>::iterator begin();
    std::set<line_no>::iterator end();
    // 返回指向待查询文件的shared_ptr
    std::shared_ptr<std::vector<std::string>> get_file() const;

private:
    std::string sought;                             // 查询单词
    std::shared_ptr<std::set<line_no>> lines;       // 出现的行号
    std::shared_ptr<std::vector<std::string>> file; // 输入文件
};

// std::ostream &operator<<(std::ostream &os, const QueryResult &result);

#endif