#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdlib>
 
using namespace std;
 
vector<int> p;
 
int find_set(int x) 
{
    return (x == p[x]) ? x : p[x] = find_set(p[x]);
}
 
void unite_set(int x, int y) 
{
    x = find_set(x);
    y = find_set(y);
    if (x == y) return;
    if (rand() % 2) swap(x, y);
    p[x] = y;
}
 
int main() 
{
    int n, m, i, j, s = 0, w;
    int ans = 0;
    cout << "Введите количество вершин: "; cin >> n;
    cout << "Введите количество ребер: "; cin >> m;
    cout << "Введите список ребер: \n";
    p.resize(n + 1);
 
    for (int k = 1; k <= n; ++k) 
        p[k] = k;
 
    vector<pair<int, pair<int, int>>> r(m);
 
    for (int k = 0; k < m; ++k) 
    {
        cin >> i >> j >> w;
        r[k] = make_pair(w, make_pair(i, j));
    }
 
    sort(r.begin(), r.end());

    cout << "\nr: \n";
    for (auto &i: r)
        cout << i.first << " " << i.second.first << " " << i.second.second << "\n";
    cout << "\n";

    for (int k = 0; k < m && s < n - 1; ++k) 
    {
        i = find_set(r[k].second.first);
        j = find_set(r[k].second.second);
        
        cout << "i: " << i << " " << "j: " << j << "\n";
            
        if (i != j) 
        {
            cout << "s: ";
            for (auto &i: p)
                cout << i << " ";
            int tmp = r[k].first;
            cout << "cur w: " << tmp << "\n";
            ans += tmp;
            s++;
            unite_set(i, j);
            cout << "ans: " << ans << "\n";    
            cout << "s: ";
            for (auto &i: p)
                cout << i << " ";
            cout << "\n\n";
        }
    }
    cout << "Длина минимального остовного дерева: " << ans << "\n";
    return 0;
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
