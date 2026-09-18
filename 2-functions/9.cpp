#include <iostream>

unsigned int sum_ternary(unsigned int a)
{
    unsigned int sum = 0;

    while (a > 0)
    {
        sum += a % 3;
        a /= 3;
    }

    return sum;
}

int main()
{
    unsigned int n, s = 0, tmp;
    std::cin >> n;

    for (unsigned int i = 0; i < n; ++i)
    {
        std::cin >> tmp;
        s += sum_ternary(tmp);
    }

    std::cout << sum_ternary(s) << std::endl;

    return 0;
}