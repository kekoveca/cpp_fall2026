#include <iostream>

void binary(unsigned int n);

void binary(unsigned int n)
{
    if (n >= 2)
    {
        binary(n / 2);
    }
    std::cout << n % 2;
}

int main()
{
    unsigned int n;
    std::cin >> n;
    binary(n);
    std::cout << std::endl;
    return 0;
}
