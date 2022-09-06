#ifndef WORD_QUERY_H
#define WORD_QUERY_H

#include "query_base.h"

// 一个WordQuery查找一个给定的string
// 它是在给定的TextQuery对象上实际执行查询的唯一一个操作
class WordQuery : public QueryBase {
    friend class Query; // Query使用WordQuery的构造函数

    WordQuery(const std::string &s);

    // 具体的类:WordQuery将定义所有继承而来的纯虚函数
    QueryResult eval(const TextQuery &t) const;
    std::string rep() const;

    std::string query_word; // 要查找的单词
};

#endif