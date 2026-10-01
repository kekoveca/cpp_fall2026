#include <iostream>

struct Event
{
    // Идентификаторы и время могут быть большими положительными числами,
    // поэтому для всех полей используем unsigned long long.
    unsigned long long ship_id;
    unsigned long long run_id;
    unsigned long long time_stamp;
    unsigned long long event_type;
};

void swap_events(Event &a, Event &b)
{
    // Меняем местами сразу целые записи, сохраняя связь между их полями.
    Event temp = a;
    a = b;
    b = temp;
}

void quick_sort(Event events[], int left, int right)
{
    // Сортировка нужна потому, что строки общего лога могут быть записаны
    // не по времени. В качестве опорного берём время среднего элемента.
    int i = left;
    int j = right;

    unsigned long long pivot =
        events[(left + right) / 2].time_stamp;

    while (i <= j)
    {
        // Слева ищем событие, которое должно находиться правее опорного.
        while (events[i].time_stamp < pivot)
            ++i;

        // Справа ищем событие, которое должно находиться левее опорного.
        while (events[j].time_stamp > pivot)
            --j;

        // Ставим найденные записи на правильные стороны относительно pivot.
        if (i <= j)
        {
            swap_events(events[i], events[j]);
            ++i;
            --j;
        }
    }

    // Независимо сортируем оставшиеся левую и правую части массива.
    if (left < j)
        quick_sort(events, left, j);

    if (i < right)
        quick_sort(events, i, right);
}

int main()
{
    int n = 0;
    std::cin >> n;

    Event all_events[10000];

    // Сначала приходится сохранить общий лог целиком: идентификатор
    // проверяемого корабля указан только после всех N строк таблицы.
    for (int i = 0; i < n; ++i)
    {
        std::cin >> all_events[i].ship_id >> all_events[i].run_id >> all_events[i].time_stamp >> all_events[i].event_type;
    }

    unsigned long long ship_for_check = 0;
    std::cin >> ship_for_check;

    // Записи остальных кораблей не влияют на законопослушность выбранного.
    // Копируем его события в отдельный массив для последующей сортировки.
    Event events[10000];
    int count = 0;

    for (int i = 0; i < n; ++i)
    {
        if (all_events[i].ship_id == ship_for_check)
        {
            events[count] = all_events[i];
            ++count;
        }
    }

    // После сортировки журнал можно анализировать в хронологическом порядке.
    if (count > 1)
    {
        quick_sort(events, 0, count - 1);
    }

    // active показывает, находится ли корабль внутри ещё не законченного курса.
    bool active = false;

    // Для активного курса храним его run_id и номер следующего обязательного
    // события: после 0 ожидается 1, после 1 — 2, после 2 — 3.
    unsigned long long current_run = 0;
    unsigned long long expected_event = 0;

    // start_time нужен для проверки, что прочие события произошли после 0.
    // last_special_time обеспечивает строгий порядок событий 0, 1, 2, 3.
    // last_event_time помогает проверить, что событие 3 произошло позже
    // всех прочих событий курса, а следующий курс не начался одновременно.
    unsigned long long start_time = 0;
    unsigned long long last_special_time = 0;
    unsigned long long last_event_time = 0;

    // Здесь храним run_id уже начавшихся курсов. Повторное начало курса
    // с прежним идентификатором означало бы второе событие 0 для этого курса.
    unsigned long long used_runs[10000];
    int used_count = 0;

    for (int i = 0; i < count; ++i)
    {
        // Ссылка позволяет читать текущую запись без копирования структуры.
        const Event &event = events[i];

        // Если активного курса нет, следующей допустимой записью выбранного
        // корабля может быть только событие 0 нового курса.
        if (!active)
        {
            if (event.event_type != 0)
            {
                std::cout << "NO\n";
                return 0;
            }

            // Разные курсы не могут происходить одновременно. Если это не
            // первый курс, его событие 0 должно быть строго позже события 3
            // предыдущего курса, даже когда сортировка поставила равные
            // time_stamp в удобном для программы порядке.
            if (used_count > 0 && event.time_stamp <= last_event_time)
            {
                std::cout << "NO\n";
                return 0;
            }

            // Проверяем, что такой run_id раньше не использовался.
            for (int j = 0; j < used_count; ++j)
            {
                if (used_runs[j] == event.run_id)
                {
                    std::cout << "NO\n";
                    return 0;
                }
            }

            used_runs[used_count] = event.run_id;
            ++used_count;

            active = true;

            current_run = event.run_id;
            expected_event = 1;

            start_time = event.time_stamp;
            last_special_time = event.time_stamp;
            last_event_time = event.time_stamp;

            continue;
        }

        // Пока курс не закончен, любая запись должна относиться к нему.
        // Это запрещает событию 0 другого курса оказаться между 0 и 3
        // текущего курса и тем самым предотвращает пересечение курсов.
        if (event.run_id != current_run)
        {
            std::cout << "NO\n";
            return 0;
        }

        // События с идентификаторами 0, 1, 2 и 3 являются обязательными.
        if (event.event_type <= 3)
        {
            // Требуем точную последовательность 0, 1, 2, 3. Эта проверка
            // также обнаруживает пропущенные и повторяющиеся события.
            if (event.event_type != expected_event)
            {
                std::cout << "NO\n";
                return 0;
            }

            // Обязательные события должны идти строго по времени.
            if (event.time_stamp <= last_special_time)
            {
                std::cout << "NO\n";
                return 0;
            }

            last_special_time = event.time_stamp;

            if (event.event_type == 3)
            {
                // Прочие события должны находиться строго между событиями
                // 0 и 3. Поэтому событие 3 обязано быть позже любой уже
                // обработанной записи текущего курса.
                if (event.time_stamp <= last_event_time)
                {
                    std::cout << "NO\n";
                    return 0;
                }

                // Все четыре обязательных события найдены, курс закончен.
                active = false;
            }
            else
            {
                // После 1 ожидаем 2, после 2 ожидаем 3.
                ++expected_event;
            }
        }
        else
        {
            // Любое другое событие разрешено только после начала курса.
            // Строгое сравнение исключает одновременность с событием 0.
            if (event.time_stamp <= start_time)
            {
                std::cout << "NO\n";
                return 0;
            }
        }

        // Запоминаем время каждой принятой записи. Оно понадобится при
        // проверке конца курса и начала следующего курса.
        last_event_time = event.time_stamp;
    }

    /*
       active может остаться true: последний курс на момент проверки лога
       разрешено завершить после любого из обязательных событий.

       Например:
       0
       0 1
       0 1 2

       Это допустимо, потому что последний курс
       может быть ещё не закончен.
    */

    std::cout << "YES\n";

    return 0;
}
