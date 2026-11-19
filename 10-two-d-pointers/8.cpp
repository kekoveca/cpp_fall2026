#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int **create(unsigned int n, unsigned int m)
{
    int **a = new int *[n];
    for (unsigned int i = 0; i < n; i++)
        a[i] = new int[m];
    return a;
}
void destroy(int **a, unsigned int n)
{
    for (unsigned int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
}
void print(int **a, unsigned int n, unsigned int m)
{
    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int j = 0; j < m; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
}
int **create_compact(int **a, unsigned int n, unsigned int m);
void print_compact(int **compact, unsigned int n, unsigned int m);
void destroy_compact(int **compact, unsigned int n);
// ваш код сюда

int **create_compact(int **a, unsigned int n, unsigned int m)
{
    // Деление с округлением вверх учитывает неполный блок на краю.
    unsigned int n_compact = n / 2 + n % 2;
    unsigned int m_compact = m / 2 + m % 2;

    int **result = create(n_compact, m_compact);

    for (unsigned int i = 0; i < n_compact; ++i)
    {
        for (unsigned int j = 0; j < m_compact; ++j)
        {
            // При двух нечётных размерах угловой блок состоит из одного элемента.
            if (i == n_compact - 1 && j == m_compact - 1 && n % 2 && m % 2)
            {
                result[i][j] = a[2 * i][2 * j];
            }
            // В неполной последней строке складываются только два элемента.
            else if (i == n_compact - 1 && n % 2)
            {
                result[i][j] = a[2 * i][2 * j];
                result[i][j] += a[2 * i][2 * j + 1];
            }
            // В неполном последнем столбце складываются только два элемента.
            else if (j == m_compact - 1 && m % 2)
            {
                result[i][j] = a[2 * i][2 * j];
                result[i][j] += a[2 * i + 1][2 * j];
            }
            // Обычный блок содержит четыре соседних элемента.
            else
            {
                result[i][j] = a[2 * i][2 * j];
                result[i][j] += a[2 * i + 1][2 * j];
                result[i][j] += a[2 * i][2 * j + 1];
                result[i][j] += a[2 * i + 1][2 * j + 1];
            }
        }
    }

    return result;
}

void print_compact(int **compact, unsigned int n, unsigned int m)
{
    unsigned int n_compact = n / 2 + n % 2;
    unsigned int m_compact = m / 2 + m % 2;
    print(compact, n_compact, m_compact);
}

void destroy_compact(int **compact, unsigned int n)
{
    unsigned int n_compact = n / 2 + n % 2;
    destroy(compact, n_compact);
}

int main()
{
    unsigned int n, m;
    cin >> n >> m;
    int **a = create(n, m);
    for (unsigned int i = 0; i < n; i++)
        for (unsigned int j = 0; j < m; j++)
            cin >> a[i][j];
    int **b = create_compact(a, n, m);
    print(a, n, m);
    print_compact(b, n, m);
    destroy(a, n);
    destroy_compact(b, n);
    return 0;
}
