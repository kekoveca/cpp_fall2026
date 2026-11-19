#include <iostream>
using namespace std;
int **transpose(int **matrix, unsigned int N, unsigned int M);
// ваш код здесь

int **transpose(int **matrix, unsigned int N, unsigned int M)
{
    // После транспонирования матрица содержит M строк и N столбцов.
    int **result = new int *[M];
    for (unsigned int i = 0; i < M; ++i)
    {
        result[i] = new int[M];
        for (unsigned int j = 0; j < N; j++)
        {
            // Строка исходной матрицы становится столбцом результата.
            result[i][j] = matrix[j][i];
        }
    }
    return result;
}

int main()
{
    int **matrix;
    unsigned int N, M;
    cin >> N >> M;
    matrix = new int *[N];
    for (unsigned int i = 0; i < N; i++)
    {
        matrix[i] = new int[M];
        for (unsigned int j = 0; j < M; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int **t = transpose(matrix, N, M);
    for (unsigned int i = 0; i < N; i++)
    {
        for (unsigned int j = 0; j < M; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    for (unsigned int i = 0; i < M; i++)
    {
        for (unsigned int j = 0; j < N; j++)
        {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }

    for (unsigned int i = 0; i < M; i++)
    {
        delete[] t[i];
    }
    delete[] t;
    for (unsigned int i = 0; i < N; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}
