#include <iostream>
#include <stack>
#include <set>

#define INF 1000000000
#define N 1000

using namespace std;

/*
 0  4 10 -1 -1 13
 4  0  7  5 -1 -1
10  7  0  1 -1  4
-1  5  1  0  1 -1
-1 -1 -1  1  0  5
13 -1  4 -1  5  0
*/

/*
-1  4  6 -1 -1 -1 33
4  -1  1 -1 -1 -1 -1
6   1 -1  5 -1 -1 27
-1 -1  5 -1  4  8 10
-1 -1 -1  4 -1  1  8
-1 -1 -1  8  1 -1  2
33 -1 27 10  8  2 -1
*/

int main(void)
{
    int n;
    int start, finish;
    set<pair<int, int>> c;
    cout << "n: "; cin >> n;
    cout << "start: "; cin >> start;
    cout << "finish: "; cin >> finish;
    
    start--;
    finish--;

    int matrix[N][N];
    int distance[N];
    int parent[N];
    bool visited[N];

    cout << "matrix: \n";
    int i;
    for (i = 0; i < n; ++i)
    {
        distance[i] = INF;
        visited[i] = true;
        for (int j = 0; j < n; ++j)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] < 0 || i == j) matrix[i][j] = INF;
        }
    }

    distance[start] = 0;
    parent[start] = start;
    c.insert(make_pair(0, start));

    while (!c.empty())
    {
        cout << "c: \n";
        for (auto &i: c)
            cout << i.first << " " << i.second << "\n";
        cout << "distance: ";
        for (int i = 0; i < n; ++i)
            if (distance[i] != INF) cout << distance[i] << " ";
            else cout << "inf ";
        cout << "\n\n";



        i = c.begin()->second;
        visited[i] = false;
        c.erase(c.begin());
        for(int j = 0; j < n; ++j)
            if(visited[j] && distance[j] > distance[i] + matrix[i][j])
            {
                c.erase(make_pair(distance[j], j));
                distance[j] = distance[i] + matrix[i][j];
                parent[j] = i;
                c.insert(make_pair(distance[j], j));
            }
    }

    int ans = distance[finish];
    if (distance[finish] < INF)
    {
        cout << "path length: " << ans << "\n";
        cout << "path: ";
        stack<int> q;
        q.push(finish);
        while(finish != start)
        {
            finish = parent[finish];
            q.push(finish);
        }
        while(!q.empty())
        {
            cout << q.top() + 1 << ' ';
            q.pop();
        }
        
    }
    else cout << "no path";
    cout << "\n";
    return 0;
}