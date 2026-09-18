#include <iostream>

int main()
{
    int n = 0;
    std::cin >> n;

    int wallets[10] = {};
    int total_gold = 0;

    // Число монет в каждом кошельке понадобится при раздаче.
    // Общая сумма позволит вычислить остаток после окончания раздачи.
    for (int i = 0; i < n; ++i)
    {
        std::cin >> wallets[i];
        total_gold += wallets[i];
    }

    int m = 0;
    std::cin >> m;

    // received[p] отмечает, получил ли участник p хотя бы одну монету.
    bool received[1000] = {};

    // position — получатель очередной монеты, happy — число получивших,
    // spent — сколько монет уже роздано.
    int position = 0;
    int happy = 0;
    int spent = 0;

    for (int i = 0; i < n; ++i)
    {
        // Для монет из кошелька i переход по кругу составляет i + 2 мест.
        int step = i + 2;

        for (int j = 0; j < wallets[i]; ++j)
        {
            // Самую первую монету отдаём участнику 0 без перехода.
            // Перед каждой следующей монетой сдвигаем позицию по кругу.
            if (spent > 0)
            {
                position = (position + step) % m;
            }

            // Повторная монета тому же участнику не увеличивает happy.
            if (!received[position])
            {
                received[position] = true;
                ++happy;
            }

            ++spent;

            // Как только получили все, выводим число оставшихся монет.
            if (happy == m)
            {
                std::cout << "YES " << total_gold - spent << '\n';
                return 0;
            }
        }
    }

    // Если монеты закончились раньше, сообщаем, сколько участников без монет.
    std::cout << "NO " << m - happy << '\n';

    return 0;
}
