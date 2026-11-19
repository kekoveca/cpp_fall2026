#include <iostream>

int main()
{
    unsigned int megabytes = 0;
    std::cin >> megabytes;

    // Адреса начинаются с нуля, поэтому наибольший адрес на единицу меньше объёма.
    unsigned long long int max_value = static_cast<unsigned long long>(megabytes) * 1024 * 1024 - 1;

    unsigned long long bit_count = 1;
    while (true)
    {
        if ((1ULL << bit_count) > max_value)
        {
            break;
        }
        ++bit_count;
    }

    // Неполная группа из восьми бит тоже требует целого байта.
    unsigned long long byte_count = bit_count / 8 + (bit_count % 8 != 0);
    std::cout << byte_count << '\n';
}
