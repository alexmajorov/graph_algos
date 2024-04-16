#include <iostream>

#define INF 1000000000
#define N 1000

/*
 0  4 10 -1 -1 13
 4  0  7  5 -1 -1
10  7  0  1 -1  4
-1  5  1  0  1 -1
-1 -1 -1  1  0  5
13 -1  4 -1  5  0
*/

using namespace std;

int main(void)
{
    int n;
    int start;
    int finish;

    cout << "Введите число вершин графа: "; cin >> n;
    cout << "Введите начальную вершину пути: "; cin >> start;
    cout << "Введите конечную вершину пути: "; cin >> finish;
    
    start--;
    finish--;
    int matrix[N][N], next[N][N];

    cout << "Введите матрицу смежности графа: \n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            cin >> matrix[i][j];

            if (matrix[i][j] < 0 || i == j) 
            {
                matrix[i][j] = INF;
                next[i][j] = -1;
            }
            else
                next[i][j] = j;
        }

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (matrix[i][j] > matrix[i][k] + matrix[k][j])
                {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                    next[i][j] = next[i][k];
                }

    if (matrix[start][finish] < INF) 
        cout << "Длина пути: " << matrix[start][finish] << "\n";
    else cout << "Пути нет\n";

    if (next[start][finish] != -1)
    {
        cout << "Путь: ";
        cout << start + 1 << ' ';
        while (start != finish)
        {
            start = next[start][finish];
            cout << start + 1 << ' ';
        }    
        cout << "\n";
    }

    return 0;
}