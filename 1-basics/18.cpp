#include <iostream>

int main()
{
    int vv, vm, l, k, n;
    std::cin >> vv >> vm >> l >> k >> n;

    if (l == 0)
    {
        std::cout << 0 << std::endl;
        return 0;
    }
    if (k == 0)
    {
        std::cout << n << std::endl;
        return 0;
    }
    if (vv == 0 && vm == 0)
    {
        std::cout << 0 << std::endl;
        return 0;
    }

    int vova_position = 0;
    int dog_position = -l;
    int bags = n;

    while (true)
    {
        if (bags > 0)
        {
            --bags;
        }

        int vova_speed = vv - bags;
        if (vova_speed < 0)
        {
            vova_speed = 0;
        }

        vova_position += vova_speed;
        dog_position += vm;

        if (dog_position >= vova_position)
        {
            std::cout << 0 << std::endl;
            break;
        }
        if (vova_position >= k)
        {
            std::cout << bags << std::endl;
            break;
        }
    }

    return 0;
}
