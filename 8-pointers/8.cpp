#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int *get_10_ints();
void return_10_ints_to_the_wilds(int *p);
// Место для вашего кода.

int *get_10_ints()
{
    // Массив создаётся в куче и остаётся доступен после выхода из функции.
    int *arr = new int[10];
    return arr;
}

void return_10_ints_to_the_wilds(int *p)
{
    // delete[] соответствует выделению массива через new[].
    delete[] p;
}

int main()
{
    int *p = get_10_ints();
    for (int i = 0; i < 10; i++)
        p[i] = i;
    for (int i = 0; i < 10; i++)
        cout << p[10 - i - 1] << " ";
    cout << endl;
    return_10_ints_to_the_wilds(p);
    return 0;
}
