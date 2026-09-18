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

    int count = 0;
    int even = 1;
    int idx = n / 2 + even * count;

    while (count < n)
    {
        idx += even * count;
        std::cout << arr[idx] << " ";
        even *= -1;
        ++count;
    }
}