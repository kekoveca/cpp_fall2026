#include <iostream>
using std::cin;
using std::cout;
using std::endl;
void swap_arrays(int n, int *array_0, int *array_1);
// Место для вашей функции.

void copy_array_reverse(int n, char *array_source, char *array_destination)
{
    for (int i = 0; i < n; ++i)
    {
        // Индекс n - i - 1 проходит исходный массив с конца.
        array_destination[i] = array_source[n - i - 1];
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
