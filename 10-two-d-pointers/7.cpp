#include <iostream>
using std::cin;
using std::cout;
using std::endl;
void sort_errors(unsigned int **errors, unsigned int n, unsigned int m);

// ваш код сюда
double mean(unsigned int *arr, size_t size)
{
    double sum = 0;
    for (size_t i = 0; i < size; ++i)
    {
        sum += arr[i];
    }
    return sum / size;
}

void swap_arrays(unsigned int **p_array_0, unsigned int **p_array_1)
{
    // Переставляем целые строки обменом их адресов.
    unsigned int *tmp = *p_array_0;
    *p_array_0 = *p_array_1;
    *p_array_1 = tmp;
}

void sort_errors(unsigned int **errors, unsigned int n, unsigned int m)
{
    // Проверка предотвращает переполнение выражения n - 1 при n == 0.
    if (n < 2)
        return;

    // Пузырьковая сортировка сравнивает средние значения соседних строк.
    for (size_t i = 0; i < n - 1; ++i)
    {
        for (size_t j = 0; j < n - 1 - i; ++j)
        {
            if (mean(errors[j], m) > mean(errors[j + 1], m))
            {
                swap_arrays(&(errors[j]), &(errors[j + 1]));
            }
        }
    }
}

int main()
{
    unsigned int n, m;
    cin >> n >> m;
    unsigned int **data = new unsigned int *[n];
    for (unsigned int i = 0; i < n; i++)
        data[i] = new unsigned int[m];
    for (unsigned int i = 0; i < n; i++)
        for (unsigned int j = 0; j < m; j++)
            cin >> data[i][j];
    sort_errors(data, n, m);
    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int j = 0; j < m; j++)
            cout << data[i][j] << " ";
        cout << endl;
    }
    for (unsigned int i = 0; i < n; i++)
        delete[] data[i];
    delete[] data;
    return 0;
}
