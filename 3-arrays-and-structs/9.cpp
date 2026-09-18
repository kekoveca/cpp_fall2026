#include <iostream>

int main()
{
    int n = 0;
    std::cin >> n;

    int matrix[10][10] = {};

    // Считываем квадратную матрицу размером n на n.
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cin >> matrix[i][j];
        }
    }

    // Меняем местами элементы относительно главной диагонали.
    // Начинаем с j = i + 1, чтобы каждую пару поменять ровно один раз.
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // После перестановок в matrix уже лежит транспонированная матрица.
    // Выводим каждую строку, разделяя элементы пробелами.
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
