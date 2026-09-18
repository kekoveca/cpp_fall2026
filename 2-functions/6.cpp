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

unsigned long long int factorial(unsigned int n)
{
    unsigned long long int result = 1;

    for (unsigned int i = 2; i <= n; ++i)
    {
        result *= i;
    }

    return result;
}

int main()
{
    unsigned int n;
    std::cin >> n;

    std::cout << sum_of_numbers(factorial(n)) << std::endl;

    return 0;
}