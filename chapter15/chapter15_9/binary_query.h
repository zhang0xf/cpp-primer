#ifndef BINARY_QUERY_H
#define BINARY_QUERY_H

#include "query_base.h"
#include "query.h"

class BinaryQuery : public QueryBase {
protected:
    BinaryQuery(const Query &q1, const Query &q2, std::string s);

    // 抽象类: BinaryQuery不定义eval

    std::string rep() const;

    Query lhs, rhs;
    std::string opSym;
};

#endif