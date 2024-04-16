/*
9
 0  2 -1  6 10 -1 -1 -1 -1 
 2  0  7  3  1 -1 -1 -1 -1  
-1  7  0 -1  9  3 -1 -1 -1 
 6  3 -1  0  2 -1  9 -1 -1 
10  1  9  2  0  5  6  3  4 
-1 -1  3 -1  5  0 -1  2  6  
-1 -1 -1  9  6 -1  0  4 -1 
-1 -1 -1 -1  3  2  4  0  3 
-1 -1 -1 -1  4  6 -1  3  0 
*/

#include <bits/stdc++.h>

#define N 16
#define INF 1000000000

int n;
int degree[N];
int matrix[N][N], distance[N][N];
std::vector<bool> visited;
std::vector<int> mem(1 << 15);

void dfs(int v)
{
    if (visited[v])
        return;
    visited[v] = true;
    for(int i = 0; i < n; i++)
        if (matrix[v][i] < INF)
            dfs(i);
    return;
}

int rec(int mask)
{
    int &res = mem[mask];
    
    if (res != -1) return res;
    if (mask == 0) return res = 0;
    
    res = INF;
    int i1;
    for (i1 = 0; (mask & (1 << i1)) == 0; ++i1);
    for (int i2 = i1 + 1; i2 < n; ++i2)
        if (mask & (1 << i2))
            res = std::min(res, distance[i1][i2] + rec(mask ^ (1 << i1) ^ (1 << i2)));
    
    return res;
}


int main(void)
{    
    int sum = 0;

    std::cout << "Введите количество вершин: "; std::cin >> n;

    std::cout << "Введите матрицу смежности графа: \n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            std::cin >> matrix[i][j];
            if (matrix[i][j] < 0 || i == j)
            {
                matrix[i][j] = INF;
                matrix[j][i] = INF;
            }
            else
            {
                sum += matrix[i][j];
                degree[i]++;
            }
        }
    
    sum /= 2;
    visited.assign(N, false);
    dfs(0);

    bool bad = false;
    for (int i = 0; i < n; ++i)
        if (!visited[i] && degree[i] > 0)
            bad = true;
    
    if (bad)
    {
        std::cout << "Граф не связен даже при удалении изолированных вершин\n";
        return 0;
    }

    memcpy(distance, matrix, sizeof(matrix));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                distance[i][j] = std::min(distance[i][j], distance[i][k] + distance[k][j]);
            
    mem.assign(1 << 15, -1);
    int mask = 0;
    for (int i = 0; i < n; ++i)
        if (degree[i] % 2 == 1)
            mask |= 1 << i;
     
    int res = sum + rec(mask);
    std::cout << "Длина пути, проходящего через все ребра: " << res << "\n";
    return 0;
}
