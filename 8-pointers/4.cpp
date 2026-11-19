#include <iostream>
using std::cout;
using std::endl;
void decr(int *px);

// Место для вашей функции.

void decr(int *px)
{
    // Разыменование позволяет изменить переменную по переданному адресу.
    *px -= 1;
}

int main()
{
    int x = 10;
    decr(&x);
    cout << x << endl;
    return 0;
}
