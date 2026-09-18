#include <iostream>

int main()
{
    size_t n = 0;
    std::cin >> n;

    int arr[1000];
    float sum = 0;
    // Сохраняем числа для второго прохода и одновременно находим их сумму.
    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
        sum += arr[i];
    }

    // Среднее значение нужно знать до проверки отдельных элементов.
    float mean = sum / n;

    // Выводим элементы, которые строго больше среднего, в исходном порядке.
    for (size_t i = 0; i < n; ++i)
    {
        if (arr[i] > mean)
        {
            std::cout << arr[i] << " ";
        }
    }
}
