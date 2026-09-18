#include <iostream>

int main()
{
    int n = 0;
    int m = 0;

    std::cin >> n >> m;

    // sums[j] накапливает сумму элементов столбца j.
    long long sums[100] = {};

    // Матрицу целиком хранить не требуется: каждый элемент сразу
    // добавляем к сумме соответствующего столбца.
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int value = 0;
            std::cin >> value;

            sums[j] += value;
        }
    }

    // Индекс первого столбца с максимальной суммой.
    int max_index = 0;

    // При равенстве сумм оставляем меньший индекс, поэтому сравнение строгое.
    for (int j = 1; j < m; ++j)
    {
        if (sums[j] > sums[max_index])
        {
            max_index = j;
        }
    }

    std::cout << max_index << '\n';

    return 0;
}
