#include <iostream>

int main()
{
    int n = 0;
    std::cin >> n;

    int wallets[10] = {};
    int total_gold = 0;

    for (int i = 0; i < n; ++i)
    {
        std::cin >> wallets[i];
        total_gold += wallets[i];
    }

    int m = 0;
    std::cin >> m;

    bool received[1000] = {};

    int position = 0;
    int happy = 0;
    int spent = 0;

    for (int i = 0; i < n; ++i)
    {
        int step = i + 2;

        for (int j = 0; j < wallets[i]; ++j)
        {
            if (spent > 0)
            {
                position = (position + step) % m;
            }

            if (!received[position])
            {
                received[position] = true;
                ++happy;
            }

            ++spent;

            if (happy == m)
            {
                std::cout << "YES " << total_gold - spent << '\n';
                return 0;
            }
        }
    }

    std::cout << "NO " << m - happy << '\n';

    return 0;
}