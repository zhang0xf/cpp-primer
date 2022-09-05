#include <vector>
#include <memory>
#include "Quote.h"

int main() {
    std::vector<Quote> basket;
    basket.push_back(Quote());
    basket.push_back(Bulk_Quote()); // 对象派生类部分被"切掉"

    // 采用间接存储的方式(存储指针/智能指针)
    std::vector<std::shared_ptr<Quote>> basket2;
    basket2.push_back(std::make_shared<Quote>());
    basket2.push_back(std::make_shared<Bulk_Quote>());

    return 0;
}