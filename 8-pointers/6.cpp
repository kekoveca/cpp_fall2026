#include <iostream>
using std::cin;
using std::cout;
using std::endl;
void swap_arrays(int n, int *array_0, int *array_1);
// Место для вашей функции.
void swap_arrays(int n, int *array_0, int *array_1)
{
    // Обрабатываем элементы двух массивов с одинаковыми индексами.
    for (int i = 0; i < n; ++i)
    {
        // Временная переменная сохраняет текущее значение первого массива.
        int tmp = array_0[i];
        array_0[i] = array_1[i];
        array_1[i] = tmp;
    }
}

int main()
{
    int a[10], *p = new int[10];
    for (int i = 0; i < 10; i++)
        cin >> a[i];
    for (int i = 0; i < 10; i++)
        p[i] = 0;
    swap_arrays(10, a, p);
    for (int i = 0; i < 10; i++)
        cout << p[i] << " ";
    cout << endl;
    delete[] p;
    return 0;
}
