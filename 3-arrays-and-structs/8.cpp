#include <iostream>

int main()
{
    int n = 0;
    int m = 0;

    std::cin >> n >> m;

    long long sums[100] = {};

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int value = 0;
            std::cin >> value;

            sums[j] += value;
        }
    }

    int max_index = 0;

    for (int j = 1; j < m; ++j)
    {
        if (sums[j] > sums[max_index])
        {
            max_index = j;
        }
    }

    std::cout << max_index << '\n';

    return 0;
}