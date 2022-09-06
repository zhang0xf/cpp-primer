#ifndef END_QUERY_H
#define END_QUERY_H

#include "binary_query.h"

class AndQuery : public BinaryQuery {
    friend Query operator&(const Query &q1, const Query &q2);

    AndQuery(const Query &left, const Query &right);

    // 具体的类: AndQuery继承了rep并且定义了其他纯虚函数

    QueryResult eval(const TextQuery &) const;
};

inline Query operator&(const Query &q1, const Query &q2) {
    return std::shared_ptr<QueryBase>(new AndQuery(q1, q2));
}

#endif