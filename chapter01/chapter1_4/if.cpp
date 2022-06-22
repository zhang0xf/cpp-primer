#include <iostream>

int main()
{
    int currVal = 0, val = 0;

    if (std::cin >> currVal)
    {
        int cnt = 1;
        while (std::cin >> val)
        {
            if (val == currVal)
            {
                ++cnt;
            }
            else
            {
                std::cout << currVal << " occurs " << cnt << " times " << std::endl;
                currVal = val; // 记住新值
                cnt = 1;       // 重置计数器
            }
        }
        // 打印最后一个值的个数
        std::cout << currVal << " occurs " << cnt << " times " << std::endl;
    }

    return 0;
}