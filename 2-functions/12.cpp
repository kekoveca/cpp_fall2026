#include <iostream>

char unleveling(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        c += 'A' - 'a';
    }

    return c;
}

char get_a_letter()
{
    char c;

    while (std::cin.get(c))
    {
        if ((c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z'))
        {
            return c;
        }
    }

    return '\0';
}

int main()
{
    for (int i = 0; i < 10; ++i)
    {
        std::cout << unleveling(get_a_letter());
    }

    std::cout << std::endl;

    return 0;
}