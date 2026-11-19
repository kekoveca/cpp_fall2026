#include <iostream>
using std::cin;
using std::cout;
using std::endl;
struct Sequence
{
    int size;  // количество чисел
    int *data; // указатель на начало массива с числами
};
void separate_odd_even(const Sequence *input, Sequence **odd, Sequence **even);
void clear(Sequence *s);

void separate_odd_even(const Sequence *input, Sequence **odd, Sequence **even)
{
    // Двойные указатели позволяют вернуть две созданные структуры.
    *odd = new Sequence{};
    *even = new Sequence{};

    size_t size = input->size;

    (*odd)->size = size;
    (*odd)->data = new int[size]{};
    size_t odd_idx = 0;

    (*even)->size = size;
    (*even)->data = new int[size]{};
    size_t even_idx = 0;

    for (size_t i = 0; i < size; ++i)
    {
        int value = input->data[i];
        if (value % 2)
        {
            (*odd)->data[odd_idx] = value;
            ++odd_idx;
        }
        else
        {
            (*even)->data[even_idx] = value;
            ++even_idx;
        }
    }

    (*odd)->size = odd_idx;
    (*even)->size = even_idx;
}

void clear(Sequence *s)
{
    // Сначала освобождаем вложенный массив, затем саму структуру.
    delete[] s->data;
    delete s;
}

int main()
{
    Sequence input;
    cin >> input.size;
    input.data = new int[input.size];
    for (int i = 0; i < input.size; i++)
        cin >> input.data[i];
    Sequence *odd, *even;
    separate_odd_even(&input, &odd, &even);
    for (int i = 0; i < odd->size; i++)
        cout << odd->data[i] << " ";
    cout << endl;
    for (int i = 0; i < even->size; i++)
        cout << even->data[i] << " ";
    cout << endl;
    clear(odd);
    clear(even);
    delete[] input.data;
    return 0;
}
