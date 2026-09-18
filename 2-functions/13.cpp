#include <iostream>

unsigned long long int get_a_hexadecimal()
{
    unsigned long long int result = 0;
    char c;
    bool valid = true;

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
        else
        {
            valid = false;
        }
    }

    if (!valid)
    {
        return 0;
    }

    return result;
}

int main()
{
    std::cout << get_a_hexadecimal() << std::endl;

    return 0;
}