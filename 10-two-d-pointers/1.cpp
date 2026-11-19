#include <iostream>
using namespace std;

void change_array(int *arr, int N);

void change_array(int *arr, int N)
{
    // Изменения через указатель сразу применяются к исходному массиву.
    for (int i = 0; i < N; ++i)
    {
        if (arr[i] % 2)
        {
            arr[i] += 2;
        }
        else
        {
            arr[i] *= 2;
        }
    }
}

int main()
{
    int N;
    cin >> N;
    int *a = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    change_array(a, N);
    for (int i = 0; i < N; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    delete[] a;
    return 0;
}
