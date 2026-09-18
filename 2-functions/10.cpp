#include <iostream>

bool is_a_number(char c)
{
    return c >= '0' && c <= '9';
}

int main()
{
    char c;
    unsigned int sum = 0;

    do
    {
        std::cin >> c;

        if (is_a_number(c))
        {
            sum += c - '0';
        }

    } while (c != '$');

    std::cout << sum << std::endl;

    return 0;
}