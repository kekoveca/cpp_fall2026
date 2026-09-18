#include <iostream>

int main()
{
    int n = 0;
    int m = 0;

    std::cin >> n >> m;

    int matrix[10][10] = {};

    // Считываем матрицу
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> matrix[i][j];
        }
    }

    // Выводим транспонированную матрицу
    for (int j = 0; j < m; ++j)
    {
        for (int i = 0; i < n; ++i)
        {
            if (i > 0)
            {
                std::cout << ' ';
            }

            std::cout << matrix[i][j];
        }

        std::cout << '\n';
    }

    return 0;
}