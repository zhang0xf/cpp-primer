#include <sstream>

#include "./text_query.h"

TextQuery::TextQuery(std::ifstream &is) :
    file(new std::vector<std::string>) {
    std::string text;
    while (getline(is, text)) // 按行读取
    {
        file->push_back(text);
        int n = file->size() - 1;      // 当前行号
        std::istringstream line(text); // 处理string的流
        std::string word;
        while (line >> word) // 行中的每一个单词
        {
            // 如果单词不在wm中,则添加记录
            auto &lines = wm[word]; // lines是一个shared_ptr,没有记录返回空指针
            if (!lines) {
                lines.reset(new std::set<line_no>); // 分配一个新的set
            }
            // 将行号插入set集合(该行中的每个word都插入行号)
            lines->insert(n); // 如果一个给定单词在同一行中出现多次，对insert的调用什么都不会做。
        }
    }
}

QueryResult TextQuery::query(const std::string &sought) const {
    static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
    // 使用find而非下标运算符查找单词,避免将单词加到wm中!
    auto loc = wm.find(sought);
    if (loc == wm.end()) {
        // 未找到
        return QueryResult(sought, nodata, file);
    } else {
        // 找到
        return QueryResult(sought, loc->second, file);
    }
}