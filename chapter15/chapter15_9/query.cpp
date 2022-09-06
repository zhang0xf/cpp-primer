#include "query.h"
#include "word_query.h"
#include "or_query.h"
#include "and_query.h"
#include "not_query.h"

Query::Query(const std::string &s) :
    q(new WordQuery(s)) {
}

Query::Query(std::shared_ptr<QueryBase> query) :
    q(query) {
}

QueryResult Query::eval(const TextQuery &t) const {
    return q->eval(t);
}

std::string Query::rep() const {
    return q->rep();
}

// Query的输出运算符
std::ostream &operator<<(std::ostream &os, const Query &query) {
    // Query::rep()通过它的QueryBase指针对rep()进行了虚调用
    return os << query.rep();
}
