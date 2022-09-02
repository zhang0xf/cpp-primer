#include <iostream>
#include "virtualbase.h"

int main() {
    BulkQuote bulkQ("bookNo", 13.99, 10, 0.5);
    std::cout << bulkQ.net_price(20) << std::endl;
    return 0;
}