#include <iostream>

int main()
{
    int x_scv, x_drone, v_scv, v_drone, x_minerals;
    std::cin >> x_scv >> x_drone >> v_scv >> v_drone >> x_minerals;

    bool skip_scv = false;
    bool skip_drone = false;

    while (true)
    {
        if (!skip_scv)
        {
            x_scv += v_scv;
        }
        if (!skip_drone)
        {
            x_drone += v_drone;
        }

        // Победитель определяется сразу после перемещения обоих юнитов.
        if (x_scv >= x_minerals && x_drone >= x_minerals)
        {
            std::cout << "both" << std::endl;
            break;
        }
        if (x_scv >= x_minerals)
        {
            std::cout << "SCV" << std::endl;
            break;
        }
        if (x_drone >= x_minerals)
        {
            std::cout << "drone" << std::endl;
            break;
        }

        // Юнит, оказавшийся на одну клетку впереди, пропускает следующий ход.
        skip_scv = x_scv == x_drone + 1;
        skip_drone = x_drone == x_scv + 1;
    }

    return 0;
}
