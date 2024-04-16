#include <set>
#include <vector>
#include <iostream>

#define INF 1000000000
 
using namespace std;

int main()
{
    int n, m, ans = 0;
    cout << "Введите количество вершин: "; cin >> n;
    cout << "Введите количество ребер: "; cin >> m;
    cout << "Введите список ребер: \n";
    vector<vector<pair<int, int>>> gr(n);
    set<pair<int, int>> st;
    vector<int> used(n, 0);
    vector<int> dist(n, INF);
    
    for (int i = 0; i < m; ++i)
    {
        int b, e, w;
        cin >> b >> e >> w;
        gr[b - 1].push_back({w, e - 1});
        gr[e - 1].push_back({w, b - 1});
    }
    
    dist[0] = 0;
    st.insert({0, 0});
    while (!st.empty())
    {
        cout << "\nst: \n";
        for (auto &i: st)
            cout << i.second + 1 << " " << i.first << "\n";
        cout << "dist: ";
        for (auto &i: dist)
            if (i == INF) cout << "inf ";
            else cout << i << " ";
        cout << "\n";

        int v = st.begin()->second;
        st.erase(st.begin());
        used[v] = 1;
        ans += dist[v];
        for (pair<int, int> p: gr[v])
        {
            if ((dist[p.second] > p.first) and !used[p.second])
            {
                st.erase({dist[p.second], p.second});
                dist[p.second] = p.first;
                st.insert({dist[p.second], p.second});
            }
        }
    }
    cout << "Длина минимального остовного дерева: " << ans << "\n";
}

/*
7 14
1 2 5
1 4 14
1 5 7
1 6 2
2 3 4
2 4 11
2 5 3
3 4 17
3 6 12
3 7 10
4 6 8
4 7 14
5 6 6
5 7 13
*/

/*
7 13
1 2 15
1 4 10
1 7 7
2 3 4
2 5 18
2 6 11
3 4 17
3 5 3
3 6 2
3 7 19
4 6 8
4 7 13
6 7 6
*/