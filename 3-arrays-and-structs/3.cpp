#include <iostream>

int main()
{
    int n = 0;
    std::cin >> n;

    int arr[1000];

    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    int m = 0;
    std::cin >> m;

    // Каждый проход выбирает максимум из ещё не обработанной части массива.
    // Выбранные m элементов постепенно собираются в конце массива.
    for (int i = n - 1; i >= n - m; --i)
    {
        int max_idx = 0;

        for (int j = 1; j <= i; ++j)
        {
            if (arr[j] > arr[max_idx])
            {
                max_idx = j;
            }
        }

        // Переносим найденный максимум на текущую позицию справа.
        int tmp = arr[max_idx];
        arr[max_idx] = arr[i];
        arr[i] = tmp;
    }

    // Выводим только выделенную часть с m наибольшими элементами.
    for (int i = n - m; i < n; ++i)
    {
        std::cout << arr[i] << " ";
    }
}
