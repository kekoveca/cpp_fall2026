#include <iostream>

int main()
{
    int n, m;
    std::cin >> n >> m;

    char arr[25][25];

    std::cin.ignore();

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin.get(arr[i][j]);
        }

        if (i < n - 1)
        {
            std::cin.ignore();
        }
    }

    for (int j = m - 1; j >= 0; --j)
    {
        for (int i = 0; i < n; ++i)
        {
            std::cout << arr[i][j];
        }

        std::cout << '\n';
    }

    return 0;
}