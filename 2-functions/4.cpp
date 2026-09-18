#include <iostream>

unsigned int sum_of_numbers(unsigned int n);

unsigned int sum_of_numbers(unsigned int n)
{
    unsigned int result = 0;
    while (n > 0)
    {
        result += n % 10;
        n /= 10;
    }
    return result;
}

int main()
{
    unsigned int n;
    std::cin >> n;
    std::cout << sum_of_numbers(n) << std::endl;
    return 0;
}
