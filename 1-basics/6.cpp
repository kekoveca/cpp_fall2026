#include <iostream>

int main()
{
    int n, m;
    std::cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
            {
                std::cout << '+';
            }
            else
            {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
