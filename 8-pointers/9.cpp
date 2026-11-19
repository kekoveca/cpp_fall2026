#include <iostream>
using namespace std;
int *copyarr(int *a, unsigned int size);
// Место для вашего кода.

int *copyarr(int *a, unsigned int size)
{
    // Копия получает собственный участок памяти, независимый от a.
    int *b = new int[size];

    for (int i = 0; i < size; ++i)
    {
        b[i] = a[i];
    }

    // Освободить возвращённый массив должен вызывающий код.
    return b;
}

int main()
{
    unsigned int n;
    int *a;
    cin >> n;
    a = new int[n];
    for (unsigned int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int *b = copyarr(a, n);
    for (unsigned int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    delete[] a;
    delete[] b;
    return 0;
}
