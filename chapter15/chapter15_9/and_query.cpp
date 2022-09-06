#include "and_query.h"

AndQuery::AndQuery(const Query &left, const Query &right) :
    BinaryQuery(left, right, "&") {
}

QueryResult AndQuery::eval(const TextQuery &text) const {
    // 通过Query成员lhs和rhs进行的虚调用
    // 调用eval返回每个对象的QueryResult
    auto left = lhs.eval(text), right = rhs.eval(text);
    auto ret_lines = std::make_shared<std::set<line_no>>();
    // 将两个范围的交集写入一个目的迭代器中
    // 本次调用的目的迭代器向ret添加元素(交集)
    std::set_intersection(left.begin(), left.end(), right.begin(), right.end(),
                          std::inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), ret_lines, left.get_file());
}

// inline Query operator&(const Query &q1, const Query &q2) {
//     return std::shared_ptr<QueryBase>(new AndQuery(q1, q2));
// }