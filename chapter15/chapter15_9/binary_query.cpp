#include "binary_query.h"

BinaryQuery::BinaryQuery(const Query &q1, const Query &q2, std::string s) :
    lhs(q1), rhs(q2), opSym(s) {
}

std::string BinaryQuery::rep() const {
    return "(" + lhs.rep() + " " + opSym + rhs.rep() + ")";
}