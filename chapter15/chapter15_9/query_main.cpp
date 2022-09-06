#include "query.h"
#include "not_query.h"
#include "or_query.h"
#include "and_query.h"

// 单词查询程序

// usage : ./bin/query_main ./data/story.txt

int main(int argc, char *argv[]) {
    if (argc > 1) {
        std::ifstream file;
        file.open(argv[1]);
        if (!file) {
            std::cout << " open file error " << std::endl;
        }

        TextQuery tq(file); // 保存文件.并建立查询map

        // 创建查询
        Query q1("Daddy");
        Query q3 = ~Query("Alice");
        Query q5 = Query("hair") | Query("Alice");

        // 执行查询
        QueryResult rq1 = q1.eval(tq);
        QueryResult rq3 = q3.eval(tq);
        QueryResult rq5 = q5.eval(tq);

        // 打印查询结果
        print(std::cout, rq1);
        print(std::cout, rq3);
        print(std::cout, rq5);
    }

    return 0;
}