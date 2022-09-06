#ifndef QUERY_BASE_H
#define QUERY_BASE_H

#include "text_query.h"

// 抽象基类, 没有public成员, 对QueryBase的使用都需要通过Query对象
class QueryBase {
    friend class Query;

protected:
    virtual ~QueryBase() = default;
    using line_no = TextQuery::line_no;

private:
    // eval返回与当前Query匹配的QueryResult
    virtual QueryResult eval(const TextQuery &) const = 0; // 纯虚函数

    // rap是表示查询的一个string
    virtual std::string rep() const = 0; // 纯虚函数
};

#endif