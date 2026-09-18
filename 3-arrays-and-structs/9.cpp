#include <iostream>

int main()
{
    int n = 0;
    std::cin >> n;

    int matrix[10][10] = {};

    // Считываем матрицу
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cin >> matrix[i][j];
        }
    }

    // Транспонируем матрицу
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // Выводим результат
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (j > 0)
            {
                std::cout << ' ';
            }

            std::cout << matrix[i][j];
        }

        std::cout << '\n';
    }

    return 0;
}