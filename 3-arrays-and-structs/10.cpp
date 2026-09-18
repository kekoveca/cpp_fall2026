#include <iostream>

int main()
{
    int n = 0;
    int m = 0;

    std::cin >> n >> m;

    int matrix[10][10] = {};

    // Сохраняем исходную матрицу размером n на m.
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> matrix[i][j];
        }
    }

    // Столбец j исходной матрицы становится строкой j результата.
    // Поэтому внешний цикл идёт по столбцам, а внутренний — по строкам.
    for (int j = 0; j < m; ++j)
    {
        for (int i = 0; i < n; ++i)
        {
            // Разделитель нужен только перед вторым и следующими элементами.
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
