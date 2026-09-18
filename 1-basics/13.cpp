#include <iostream>

int main()
{
    unsigned long long a, b, c;
    std::cin >> a >> b >> c;

    // Находим НОД чисел a и b алгоритмом Евклида.
    unsigned long long left = a;
    unsigned long long right = b;
    while (right != 0)
    {
        unsigned long long remainder = left % right;
        left = right;
        right = remainder;
    }

    // НОК(a, b) = a / НОД(a, b) * b.
    unsigned long long lcm = a / left * b;

    // Находим НОД текущего НОК и третьего числа.
    left = lcm;
    right = c;
    while (right != 0)
    {
        unsigned long long remainder = left % right;
        left = right;
        right = remainder;
    }

    std::cout << lcm / left * c << std::endl;
    return 0;
}
