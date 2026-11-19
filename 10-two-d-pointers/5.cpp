#include <iostream>
using namespace std;
void doubling(int **arr, unsigned int N);
// ваш код здесь

void doubling(int **arr, unsigned int N)
{
    // Двойной указатель позволяет заменить адрес массива у вызывающего кода.
    size_t new_size = 2 * N;
    int *new_arr = new int[new_size]{};
    for (size_t i = 0; i < N; ++i)
    {
        new_arr[i] = (*arr)[i];
    }
    // После освобождения старого массива сохраняем адрес нового.
    delete[] *arr;
    *arr = new_arr;
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int up = 0; up < 5; up++)
    {
        for (int i = 0; i < n; i++)
            a[i] = n - i;
        doubling(&a, n);
        for (int i = 0; i < n; i++)
        {
            if (a[i] != n - i)
            {
                cout << "NOPE" << endl;
                return 0;
            }
        }
        n *= 2;
    }
    delete[] a;
    cout << "YEP" << endl;
    return 0;
}
