#include <iostream>
#include <bit>

int main()
{
    unsigned int megabytes = 0;
    std::cin >> megabytes;

    unsigned long long bytes = static_cast<unsigned long long>(megabytes) * 1024 * 1024;

    if (bytes == 0)
    {
        std::cout << 0;
        return 0;
    }

    // bit_width определяет число бит для наибольшего адреса bytes - 1.
    unsigned long long bit_count = std::bit_width(bytes - 1);
    // Округляем число бит вверх до целого количества байт.
    unsigned long long byte_count = bit_count / 8 + (bit_count % 8 != 0);
    std::cout << byte_count << '\n';
}
