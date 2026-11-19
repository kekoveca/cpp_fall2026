#include <iostream>
using namespace std;

struct Matrix
{
    int **data;
    int n, m;
};

void init(Matrix *matrix);
void clean(Matrix *matrix);
void expand(Matrix *matrix, int n_minus, int n_plus, int m_minus, int m_plus);

// ваш код будет здесь

void init(Matrix *matrix)
{
    // data хранит массив указателей, каждый из которых задаёт отдельную строку.
    matrix->data = new int *[matrix->n];
    for (int i = 0; i < matrix->n; ++i)
    {
        matrix->data[i] = new int[matrix->m]{}; // Cразу инициализация нулями {}.
    }
}

void clean(Matrix *matrix)
{
    // Строки и массив указателей были выделены отдельно и удаляются по очереди.
    for (int i = 0; i < matrix->n; ++i)
    {
        delete[] matrix->data[i];
    }
    delete[] matrix->data;
}

void expand(Matrix *matrix, int n_minus, int n_plus, int m_minus, int m_plus)
{
    Matrix tmp;
    tmp.n = n_minus + matrix->n + n_plus;
    tmp.m = m_minus + matrix->m + m_plus;

    // Нулевая инициализация оставляет добавленные поля рамки заполненными нулями.
    init(&tmp);

    for (int i = n_minus; i < n_minus + matrix->n; ++i)
    {
        for (int j = m_minus; j < m_minus + matrix->m; ++j)
        {
            // Смещение помещает исходную матрицу внутрь новой рамки.
            tmp.data[i][j] = matrix->data[i - n_minus][j - m_minus];
        }
    }

    // После удаления старых данных передаём исходному объекту владение tmp.data.
    // matrix = &tmp не сработает, так как tmp локальная и удалится после выхода из функции.
    // *matrix = tmp выполняет копирование указателей, но сама матрица остается на куче и не копируется.
    clean(matrix);
    *matrix = tmp;
}

int main()
{
    Matrix matrix;
    cin >> matrix.n >> matrix.m;
    init(&matrix);
    for (int i = 0; i < matrix.n; i++)
        for (int j = 0; j < matrix.m; j++)
            cin >> matrix.data[i][j];

    int n_minus, n_plus, m_minus, m_plus;
    cin >> n_minus >> n_plus >> m_minus >> m_plus;

    expand(&matrix, n_minus, n_plus, m_minus, m_plus);

    for (int i = 0; i < matrix.n; i++)
    {
        for (int j = 0; j < matrix.m; j++)
            cout << matrix.data[i][j];
        cout << endl;
    }

    clean(&matrix);
    return 0;
}
