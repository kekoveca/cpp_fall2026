#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int number = 1; // Первое проверяемое число будет 2.
    int prime_count = 0;

    while (prime_count < n)
    {
        ++number;
        bool is_prime = true;

        // Достаточно проверить делители до квадратного корня из number.
        for (int divisor = 2; divisor <= number / divisor; ++divisor)
        {
            if (number % divisor == 0)
            {
                is_prime = false;
                break;
            }
        }

        if (is_prime)
        {
            // Останавливаемся, когда найдено n простых чисел.
            ++prime_count;
        }
    }

    std::cout << number << std::endl;
    return 0;
}
