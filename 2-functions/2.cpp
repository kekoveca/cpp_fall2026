#include <iostream>

bool is_simple(int n);

bool is_simple(int n)
{
    if (n <= 0)
    {
        return false;
    }

    for (int divisor = 2; divisor <= n / divisor; ++divisor)
    {
        if (n % divisor == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (is_simple(i))
        {
            std::cout << i << ' ';
        }
    }
    std::cout << std::endl;
    return 0;
}
