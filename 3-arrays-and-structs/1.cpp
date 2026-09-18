#include <iostream>

int main()
{
    size_t n = 0;
    std::cin >> n;

    int arr[1000];

    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
    }

    for (size_t i = 0; i < n; ++i)
    {
        std::cout << arr[n - i - 1] << " ";
    }
}