#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int heaviest_index = 0;
    double greatest_mass = 0;

    for (int i = 0; i < n; ++i)
    {
        double radius, height, density;
        std::cin >> radius >> height >> density;

        // Общий для всех цилиндров множитель pi не влияет на сравнение масс.
        double mass = radius * radius * height * density;
        if (i == 0 || mass > greatest_mass)
        {
            greatest_mass = mass;
            heaviest_index = i;
        }
    }

    std::cout << heaviest_index << std::endl;
    return 0;
}
