#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int result = 0;
    int greatest_absolute_value = 0;

    for (int i = 0; i < n; ++i)
    {
        int number;
        std::cin >> number;

        int absolute_value = number;
        if (absolute_value < 0)
        {
            absolute_value = -absolute_value;
        }

        if (absolute_value > greatest_absolute_value)
        {
            greatest_absolute_value = absolute_value;
            result = number;
        }
    }

    std::cout << result << std::endl;
    return 0;
}
