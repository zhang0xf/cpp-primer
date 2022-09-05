#include "basket.h"

void Basket::add_item(const Quote &sale) {
    items.insert(std::shared_ptr<Quote>(sale.clone())); // 拷贝给定的对象
}

void Basket::add_item(Quote &&sale) {
    items.insert(std::shared_ptr<Quote>(std::move(sale).clone())); // 移动给定的对象
}

void Basket::add_item(const std::shared_ptr<Quote> &sale) {
    items.insert(sale);
}

double Basket::total_receipt(std::ostream &os) {
    double sum = 0.0; // 保存实际计算出的总价格
    // items指向ISBN相同的一批元素中的第一个
    // upper_bound返回一个迭代器,该迭代器指向这批元素的尾后位置
    for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)) {
        // 打印该书籍对应的项目
        sum += print_total(os, **iter, items.count(*iter)); // **iter: 解引用shared_ptr
    }
    os << "Total Sale: " << sum << std::endl;
    return sum;
}