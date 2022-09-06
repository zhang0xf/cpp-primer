#ifndef QUERY_H
#define QUERY_H

#include <string>
#include <memory.h>

#include "text_query.h"
#include "query_base.h"

// 对外提供接口,同时隐藏了QueryBase的继承体系
// 每个Query都含有一个指向QueryBase对象的shared_ptr

class Query {
    friend Query operator~(const Query &);
    friend Query operator|(const Query &, const Query &);
    friend Query operator&(const Query &, const Query &);

public:
    Query(const std::string &); // 构建一个新的wordquery

    // 接口函数:调用对应的QueryBase操作
    QueryResult eval(const TextQuery &t) const;
    std::string rep() const;

private:
    Query(std::shared_ptr<QueryBase> query); // 私有:隐藏QueryBase
    std::shared_ptr<QueryBase> q;
};

std::ostream &operator<<(std::ostream &os, const Query &query);

#endif