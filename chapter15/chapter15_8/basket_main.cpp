#include "basket.h"

int main() {
    Basket basket;

    Quote q1 = Quote();
    Bulk_Quote b1 = Bulk_Quote();

    basket.add_item(q1);
    basket.add_item(b1);

    basket.add_item(Quote());
    basket.add_item(Bulk_Quote());
    return 0;
}