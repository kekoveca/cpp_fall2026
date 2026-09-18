#include <iostream>

int main()
{
    int n = 0;
    std::cin >> n;

    int arr[1000];

    for (int i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    int m = 0;
    std::cin >> m;

    for (int i = n - 1; i >= n - m; --i)
    {
        int max_idx = 0;

        for (int j = 1; j <= i; ++j)
        {
            if (arr[j] > arr[max_idx])
            {
                max_idx = j;
            }
        }

        int tmp = arr[max_idx];
        arr[max_idx] = arr[i];
        arr[i] = tmp;
    }

    for (int i = n - m; i < n; ++i)
    {
        std::cout << arr[i] << " ";
    }
}