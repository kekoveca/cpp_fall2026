#include <iostream>

int main()
{
    size_t n = 0;
    std::cin >> n;

    int arr[1000];
    float sum = 0;
    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
        sum += arr[i];
    }

    float mean = sum / n;

    for (size_t i = 0; i < n; ++i)
    {
        if (arr[i] > mean)
        {
            std::cout << arr[i] << " ";
        }
    }
}