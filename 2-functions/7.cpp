#include <iostream>

unsigned int sum_of_numbers(unsigned long long int n)
{
    unsigned int res = 0;

    while (n)
    {
        res += n % 10;
        n /= 10;
    }

    return res;
}

unsigned long long int fibonacci(unsigned int n)
{
    if (n == 1)
    {
        return 0;
    }

    if (n == 2)
    {
        return 1;
    }

    unsigned long long int a = 0;
    unsigned long long int b = 1;
    unsigned long long int next = 0;

    for (unsigned int i = 3; i <= n; ++i)
    {
        next = a + b;
        a = b;
        b = next;
    }

    return b;
}

int main()
{
    unsigned int n;
    std::cin >> n;

    std::cout << sum_of_numbers(fibonacci(n)) << std::endl;

    return 0;
}