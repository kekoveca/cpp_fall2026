#include <iostream>

void selection_sort(int n, int *arr, bool reverse = false)
{
    // На каждом проходе выбираем крайний элемент из неотсортированной части.
    // Для обычного порядка это максимум, для обратного — минимум.
    for (int i = n - 1; i > 0; --i)
    {
        int idx = 0;

        for (int j = 1; j <= i; ++j)
        {
            if ((reverse && arr[j] < arr[idx]) ||
                (!reverse && arr[j] > arr[idx]))
            {
                idx = j;
            }
        }

        // Ставим выбранный элемент в конец текущей части массива.
        int tmp = arr[idx];
        arr[idx] = arr[i];
        arr[i] = tmp;
    }
}

int main()
{
    int n = 0;
    std::cin >> n;

    int nonneg[1000];
    int negative[1000];
    int counter_nonneg = 0;
    int counter_negative = 0;

    // Разделяем входные числа: ноль относится к неотрицательным.
    for (int i = 0; i < n; ++i)
    {
        int temp = 0;
        std::cin >> temp;

        if (temp >= 0)
        {
            nonneg[counter_nonneg] = temp;
            ++counter_nonneg;
        }
        else
        {
            negative[counter_negative] = temp;
            ++counter_negative;
        }
    }

    // Неотрицательные сортируем по возрастанию, отрицательные по убыванию.
    selection_sort(counter_nonneg, nonneg);
    selection_sort(counter_negative, negative, true);

    // Сначала выводим одну группу, затем другую.
    for (int i = 0; i < counter_nonneg; ++i)
    {
        std::cout << nonneg[i] << " ";
    }

    for (int i = 0; i < counter_negative; ++i)
    {
        std::cout << negative[i] << " ";
    }
}
