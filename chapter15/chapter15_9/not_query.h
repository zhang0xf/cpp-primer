#ifndef NOT_QUERY_H
#define NOT_QUERY_H

#include "query_base.h"
#include "query.h"

// ～取反运算符

class NotQuery : public QueryBase {
    friend Query operator~(const Query &);

    NotQuery(const Query &q);

    // 具体的类: NotQuery将定义所有继承而来的纯虚函数
    QueryResult eval(const TextQuery &t) const;
    std::string rep() const;

    Query query;
};

// inline通常放在头文件
inline Query operator~(const Query &operand) {
    return std::shared_ptr<QueryBase>(new NotQuery(operand));
    // std::shared_ptr<QueryBase> p = std::make_shared<NotQuery>(operand);
    // return Query(p);
}

#endif