#include <iostream>
using namespace std;
struct Crystal
{
    double length;           // длина кристалла
    double width;            // характерная толщина кристалла
    unsigned int facets;     // количество граней
    unsigned long int color; // код цвета
    unsigned int defects;    // количество дефектов
};
struct Category
{
    char name[100];                        // название категории
    double length_min, length_max;         // допустимая длина кристалла
    double width_min, width_max;           // допустимая характерная толщина кристалла
    unsigned int facets_min, facets_max;   // допустимое количество граней
    unsigned long int colors[5];           // допустимые коды цвета
    unsigned int defects_min, defects_max; // допустимое количество дефектов
};
Category categories[10];

int determine_category(Crystal crystal);

int determine_category(Crystal crystal)
{
    // Проверяем категории по возрастанию индексов. Поэтому первая
    // подходящая категория автоматически имеет наименьший индекс.
    for (int i = 0; i < 10; ++i)
    {
        // Ссылка позволяет обращаться к текущей категории без её копирования.
        // const запрещает случайно изменить данные глобального массива.
        const Category &category = categories[i];

        // Нижняя граница длины включена. Если длина немного меньше неё,
        // но разница строго меньше 0.001, числа считаются одинаковыми.
        if (crystal.length < category.length_min &&
            category.length_min - crystal.length >= 0.001)
        {
            continue;
        }

        // Для верхней границы действует то же правило сравнения double.
        // Разница ровно 0.001 уже не считается допустимой погрешностью.
        if (crystal.length > category.length_max &&
            crystal.length - category.length_max >= 0.001)
        {
            continue;
        }

        // Проверяем нижнюю границу толщины с допуском для double.
        if (crystal.width < category.width_min &&
            category.width_min - crystal.width >= 0.001)
        {
            continue;
        }

        // Проверяем верхнюю границу толщины с тем же допуском.
        if (crystal.width > category.width_max &&
            crystal.width - category.width_max >= 0.001)
        {
            continue;
        }

        // Количество граней — целое число, поэтому здесь погрешность
        // не нужна. Обе границы диапазона считаются допустимыми.
        if (crystal.facets < category.facets_min ||
            crystal.facets > category.facets_max)
        {
            continue;
        }

        // Кристалл подходит по цвету, если его код совпал хотя бы
        // с одним из пяти разрешённых кодов текущей категории.
        bool correct_color = false;

        for (int j = 0; j < 5; ++j)
        {
            if (crystal.color == category.colors[j])
            {
                correct_color = true;
                break;
            }
        }

        if (!correct_color)
        {
            continue;
        }

        // Количество дефектов также должно лежать в замкнутом диапазоне.
        if (crystal.defects < category.defects_min ||
            crystal.defects > category.defects_max)
        {
            continue;
        }

        // Все характеристики прошли проверку. Поскольку категории
        // просматриваются слева направо, меньшего подходящего индекса нет.
        return i;
    }

    // Ни одна из десяти категорий не удовлетворяет всем требованиям.
    return -1;
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        cin >> categories[i].name >> categories[i].length_min >> categories[i].length_max >> categories[i].width_min >> categories[i].width_max >> categories[i].facets_min >> categories[i].facets_max;
        for (int j = 0; j < 5; j++)
            cin >> categories[i].colors[j];
        cin >> categories[i].defects_min >> categories[i].defects_max;
    }
    int n;
    cin >> n;
    int quantities[10] = {0};
    for (int i = 0; i < n; i++)
    {
        Crystal crystal;
        cin >> crystal.length >> crystal.width >> crystal.facets >> crystal.color >> crystal.defects;
        int category = determine_category(crystal);
        if (category < 0 || category > 9)
            continue;
        quantities[category]++;
    }
    for (int i = 0; i < 10; i++)
        cout << quantities[i] << " ";
    cout << endl;
    return 0;
}
