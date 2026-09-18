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

    int count = 0;
    int even = 1;
    // Начинаем с середины массива; even задаёт направление следующего шага.
    int idx = n / 2 + even * count;

    // После середины идём на 1 позицию влево, на 2 вправо,
    // на 3 влево и так далее, пока не выведем все n элементов.
    while (count < n)
    {
        idx += even * count;
        std::cout << arr[idx] << " ";
        even *= -1;
        ++count;
    }
}
