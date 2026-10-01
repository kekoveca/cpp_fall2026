#include <iostream>

struct CrewMember
{
    // Для каждого встреченного id храним только данные, необходимые
    // для выбора: число сканирований и границы нейронной активности.
    unsigned long long id;
    int scans;
    double min_neural_activity;
    double max_neural_activity;
};

int main()
{
    int n = 0;
    std::cin >> n;

    // В худшем случае все N записей принадлежат разным людям,
    // поэтому массива из 1000 элементов достаточно.
    CrewMember members[1000];
    int members_count = 0;

    for (int i = 0; i < n; ++i)
    {
        unsigned long long time_stamp = 0;
        unsigned long long id = 0;
        double vit_d = 0;
        double acat = 0;
        double anti_tg = 0;
        double neural_activity = 0;
        double mch = 0;

        // Все семь столбцов нужно считать, хотя для поиска сайлона
        // используются только id и neural_activity.
        std::cin >> time_stamp >> id >> vit_d >> acat >> anti_tg >>
            neural_activity >> mch;

        // Ищем, встречался ли этот член экипажа в предыдущих строках.
        // Порядок строк по времени и id для такого поиска не имеет значения.
        int member_index = -1;
        for (int j = 0; j < members_count; ++j)
        {
            if (members[j].id == id)
            {
                member_index = j;
                break;
            }
        }

        if (member_index == -1)
        {
            // Первое сканирование создаёт новую запись. Текущее значение
            // одновременно является минимумом и максимумом активности.
            members[members_count].id = id;
            members[members_count].scans = 1;
            members[members_count].min_neural_activity = neural_activity;
            members[members_count].max_neural_activity = neural_activity;
            ++members_count;
        }
        else
        {
            // Для уже известного человека обновляем число сканирований
            // и, если требуется, одну из границ активности.
            ++members[member_index].scans;

            if (neural_activity <
                members[member_index].min_neural_activity)
            {
                members[member_index].min_neural_activity = neural_activity;
            }

            if (neural_activity >
                members[member_index].max_neural_activity)
            {
                members[member_index].max_neural_activity = neural_activity;
            }
        }
    }

    // Индекс -1 означает, что подходящего подозреваемого пока нет.
    int cylon_index = -1;
    double smallest_difference = 0;

    for (int i = 0; i < members_count; ++i)
    {
        // Человека с единственным сканированием исключаем из подозреваемых.
        if (members[i].scans < 2)
        {
            continue;
        }

        double difference = members[i].max_neural_activity -
                            members[i].min_neural_activity;

        // Первый допустимый кандидат становится текущим лучшим.
        // Далее выбираем меньший разброс. При одинаковом разбросе
        // по условию выигрывает кандидат с большим максимумом активности.
        if (cylon_index == -1 ||
            difference < smallest_difference ||
            (difference == smallest_difference &&
             members[i].max_neural_activity >
                 members[cylon_index].max_neural_activity))
        {
            cylon_index = i;
            smallest_difference = difference;
        }
    }

    if (cylon_index == -1)
    {
        // Все члены экипажа встретились в таблице не более одного раза.
        std::cout << -1 << std::endl;
    }
    else
    {
        std::cout << members[cylon_index].id << std::endl;
    }

    return 0;
}
