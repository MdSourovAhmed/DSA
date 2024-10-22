#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 9;
vector<int> g[N];
bool vis[N];
bool dfs(int v, int par)
{
    vis[v] = 1;
    bool isCycle = false;
    for (int cld : g[v])
    {
        if (vis[cld] && cld == par)
            continue;
        if (vis[cld])
            return true;
        isCycle |= dfs(cld, v);
    }
    return isCycle;
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
    bool isLooped = false;
    for (int i = 1; i <= nd; ++i)
    {
        if (vis[i])
            continue;
        if (dfs(i, 0))
        {
            isLooped = true;
            break;
        }
    }
    cout << (isLooped ? "Loop exists.\n" : "Loop doesn't exist.\n");

    return 0;
}
