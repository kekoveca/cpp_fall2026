#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    // Находим наибольшую степень двойки, не превосходящую n.
    int power = 1;
    while (power <= n / 2)
    {
        power *= 2;
    }

    // Проверяем разряды от старшего к младшему.
    while (power > 0)
    {
        if (n >= power)
        {
            std::cout << 1;
            n -= power;
        }
        else
        {
            std::cout << 0;
        }

        power /= 2;
    }

    std::cout << std::endl;
    return 0;
}
