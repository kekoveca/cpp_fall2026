#include <iostream>

int main()
{
    int n = 0;
    std::cin >> n;

    int arr[1000];
    bool selected[1000] = {};

    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    int m = 0;
    std::cin >> m;

    for (int k = 0; k < m; ++k)
    {
        int max_idx = -1;

        for (int i = 0; i < n; ++i)
        {
            if (!selected[i] && (max_idx == -1 || arr[i] > arr[max_idx]))
            {
                max_idx = i;
            }
        }

        selected[max_idx] = true;
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (selected[i])
        {
            if (count > 0)
            {
                std::cout << " ";
            }

            std::cout << arr[i];
            count++;
        }
    }
}