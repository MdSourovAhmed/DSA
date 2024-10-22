#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 9;
vector<int> g[N];
bool vis[N];
int lvl[N];

void bfs(int source)
{
    queue<int> q;
    q.push(source);
    vis[source] = true;

    while (!q.empty())
    {
        int cur_v = q.front();
        q.pop();
        cout << cur_v << " ";
        for (int child : g[cur_v])
        {
            if (vis[child])
                continue;
            q.push(child);
            vis[child] = true;
            lvl[child] = lvl[cur_v] + 1;
        }
    }
    cout << endl;
}

int main()
{
    int nd, edg;
    cin >> nd >> edg;
    int eg = edg;
    while (eg--)
    {
        int v1, v2, w;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    bfs(1);

    for (int i = 1; i <= nd; ++i)
        cout << i << ": " << lvl[i] << endl;
    return 0;
}

// 13 13
// 1 2
// 1 3
// 1 13
// 2 5
// 5 6
// 5 7
// 5 8
// 8 12
// 3 4
// 4 9
// 4 10    
// 10 11
// 9 11