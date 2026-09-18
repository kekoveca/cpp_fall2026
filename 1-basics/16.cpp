#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int maximum = 0;
    int count = 0;

    for (int i = 0; i < n; ++i)
    {
        int number;
        std::cin >> number;

        // Новый максимум встречен пока один раз.
        if (i == 0 || number > maximum)
        {
            maximum = number;
            count = 1;
        }
        // Если число равно максимуму, увеличиваем счётчик.
        else if (number == maximum)
        {
            ++count;
        }
    }

    std::cout << count << std::endl;
    return 0;
}
