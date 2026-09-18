#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int distance = i - n / 2;
        if (distance < 0)
        {
            distance = -distance;
        }

        for (int j = 0; j < distance; ++j)
        {
            std::cout << ' ';
        }

        for (int j = 0; j < n - 2 * distance; ++j)
        {
            std::cout << '+';
        }

        std::cout << std::endl;
    }

    return 0;
}
