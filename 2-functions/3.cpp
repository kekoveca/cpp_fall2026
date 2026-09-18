#include <iostream>

int sum(int a, int b);

int sum(int a, int b)
{
    return a + b;
}

int main()
{
    int n, res = 0;
    std::cin >> n;
    while (n)
    {
        int number = n % 10;
        res = sum(res, number);
        n /= 10;
    }
    std::cout << res << std::endl;
    return 0;
}
