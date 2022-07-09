#include <iostream>
#include "./hasPtr.h"

void HasPtr::print()
{
    std::cout << "string is " << *(this->p) << std::endl;
}
