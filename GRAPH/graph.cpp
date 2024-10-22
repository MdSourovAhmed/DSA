#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e7;
const ll Mod = 1e7 + 9;
vector<pair<int, int>> Wg[N];
vector<int> g[N];
bool vis[N];
vector<vector<int>> C_c;
vector<int> cc;
void dfs(int v)
{
    vis[v] = 1;
    cc.push_back(v);
    for (int child : g[v])
    {
        // cout << "p-> " << v << "->child " << child << endl;
        if (vis[child])
            continue;
        dfs(child);
    }
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
        // cin >> w;
        // Wg[v1].push_back({v2, w}); //Weighted GRAPH
        // Wg[v2].push_back({v1, w});
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    for (int i = 1; i <= nd; ++i)
    {
        if (vis[i])
            continue;
        cc.clear();
        dfs(i);
        C_c.push_back(cc);
    }

    cout << C_c.size() << endl;
    for (auto a : C_c)
    {
        for (int b : a)
            cout << b << " ";
        cout << endl;
    }
    return 0;
}
