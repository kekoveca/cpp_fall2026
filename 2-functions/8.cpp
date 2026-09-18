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

unsigned long long int nonacci(unsigned int n)
{
    if (n < 8)
    {
        return 0;
    }

    if (n == 8)
    {
        return 1;
    }

    unsigned long long int a = 0;
    unsigned long long int b = 0;
    unsigned long long int c = 0;
    unsigned long long int d = 0;
    unsigned long long int e = 0;
    unsigned long long int f = 0;
    unsigned long long int g = 0;
    unsigned long long int h = 0;
    unsigned long long int k = 1;

    for (unsigned int i = 8; i < n; ++i)
    {
        unsigned long long int next =
            a + b + c + d + e + f + g + h + k;

        a = b;
        b = c;
        c = d;
        d = e;
        e = f;
        f = g;
        g = h;
        h = k;
        k = next;
    }

    return k;
}

int main()
{
    unsigned int n;
    std::cin >> n;

    std::cout << sum_of_numbers(nonacci(n)) << std::endl;

    return 0;
}