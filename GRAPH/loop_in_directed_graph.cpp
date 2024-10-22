#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e7;
const ll Mod = 1e7 + 9;
vector<int> g[N], topo;
stack<int> st;
bool vis[N], vis2[N];
// vis2 array is used to track the each time dfs call
// and if vis[v] & vis2[v] are visited we can say there exists a cycle
// we make each node 0 again to kepp track for the new calls
bool dfs(int v)
{
    vis[v] = 1;
    vis2[v] = 1;
    for (int child : g[v])
    {
        if (vis[child])
            if (vis2[child])
                return true;
        if (dfs(child))
            return true;
    }
    vis2[v] = 0;
    return false;
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
        // directed Graph
        g[v1].push_back(v2);
    }

    bool ans = false;

    for (int i = 1; i <= nd; ++i)
    {
        if (vis[i])
            continue;
        if (dfs(i))
        {
            ans = true;
            break;
        }
    }

    cout << (ans ? "yes" : "no") << endl;

    return 0;
}

// 9 10
// 1 2
// 2 3
// 3 4
// 4 5
// 6 5
// 3 6
// 7 2
// 7 8
// 8 9
// 9 6
