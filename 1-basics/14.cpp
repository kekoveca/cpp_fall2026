#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    if (!n) // Если n = 0, выводим 0
    {
        std::cout << '0' << std::endl;
        return 0;
    }

    int ones = 0;
    int zeros = 0;

    // Последовательно считаем цифры двоичной записи, начиная с младшей.
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            ++ones;
        }
        else
        {
            ++zeros;
        }
        n /= 2;
    }

    // Сначала печатаем все единицы, затем все нули.
    for (int i = 0; i < ones; ++i)
    {
        std::cout << '1';
    }
    for (int i = 0; i < zeros; ++i)
    {
        std::cout << '0';
    }

    std::cout << std::endl;
    return 0;
}
