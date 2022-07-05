#include <set>

#include "../sale_items.h"

bool compare_isbn(const Sales_item &lhs, const Sales_item &rhs)
{
    return lhs.isbn() < rhs.isbn();
}

int main()
{
    // set关键字要求具有行为正常的<比较运算
    // book_store中可以存在相同的isbn
    // book_store的元素以isbn进行排序
    // 参数"decltype(compareIsbn) *"表示函数指针
    std::multiset<Sales_item, decltype(compare_isbn) *> book_store(compare_isbn);

    return 0;
}