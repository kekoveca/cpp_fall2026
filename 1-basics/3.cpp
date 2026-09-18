#include <iostream>

int main()
{
    int number;
    std::cin >> number;

    if (number % 13 == 0)
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }

    return 0;
}
