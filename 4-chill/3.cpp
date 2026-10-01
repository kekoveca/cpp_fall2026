#include <iostream>

int main()
{
    unsigned int x;
    unsigned int mask = 0b00000000000000000000000000000001;
    std::cin >> x;

    for (int i = 0; i < 32; ++i)
    {
        if (x & mask)
        {
            std::cout << 1;
        }
        else
        {
            std::cout << 0;
        }
        mask = mask << 1;

        if (!((i + 1) % 4))
        {
            std::cout << ' ';
        }
        if (!((i + 1) % 8))
        {
            std::cout << ' ';
        }
    }
}