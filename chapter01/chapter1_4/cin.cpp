#include <iostream>

int main()
{
    int sum = 0, val = 0;
    while (std::cin >> val)
    {
        sum += val;
    }
    std::cout << "sum of 1 ~ 10 is " << sum << std::endl;
    return 0;
}