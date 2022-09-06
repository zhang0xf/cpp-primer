#include "or_query.h"

OrQuery::OrQuery(const Query &left, const Query &right) :
    BinaryQuery(left, right, "|") {
}

// 注意:Query存在递归
QueryResult OrQuery::eval(const TextQuery &text) const {
    // 通过Query成员lhs和rhs进行的虚调用
    // 调用eval返回每个对象的QueryResult
    auto right = rhs.eval(text), left = lhs.eval(text);
    // 将左侧运算对象行号拷贝到set
    auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());
    // 插入右侧运算对象所得的行号
    ret_lines->insert(right.begin(), right.end());
    // 返回一个新的QueryResult(并集)
    return QueryResult(rep(), ret_lines, left.get_file());
}

// inline Query operator|(const Query &q1, const Query &q2) {
//     return std::shared_ptr<QueryBase>(new OrQuery(q1, q2));
// }