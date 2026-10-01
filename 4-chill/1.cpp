#include <iostream>

int main()
{
    unsigned int x;
    unsigned int mask = 0b10000000000000000000000000000000;
    std::cin >> x;

    while (mask)
    {
        if (x & mask)
        {
            std::cout << 1;
        }
        else
        {
            std::cout << 0;
        }
        mask = mask >> 1;
    }
}