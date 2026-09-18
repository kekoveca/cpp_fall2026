#include <iostream>

unsigned long long int get_really_any_hexadecimal()
{
    unsigned long long int result = 0;
    char c;

    while (std::cin.get(c))
    {
        if (c == ' ' || c == '\n')
        {
            break;
        }

        if (c >= '0' && c <= '9')
        {
            result = result * 16 + (c - '0');
        }
        else if (c >= 'A' && c <= 'F')
        {
            result = result * 16 + (c - 'A' + 10);
        }
        else if (c >= 'a' && c <= 'f')
        {
            result = result * 16 + (c - 'a' + 10);
        }
    }

    return result;
}

int main()
{
    std::cout << get_really_any_hexadecimal() << std::endl;

    return 0;
}