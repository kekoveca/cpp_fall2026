#include <iostream>

char leveling(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c - 'A' + 'a';
    }

    return c;
}

int main()
{
    char c;

    do
    {
        std::cin.get(c);
        std::cout << leveling(c);

    } while (c != '\n');

    return 0;
}