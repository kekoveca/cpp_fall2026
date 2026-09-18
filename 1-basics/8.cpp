#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        if (n % i == 0)
        {
            if (i != 1)
            {
                std::cout << ' ';
            }
            std::cout << i;
        }
    }

    std::cout << std::endl;
    return 0;
}
