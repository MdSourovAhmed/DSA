#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 9;
vector<int> g[N];
// bool vis[N];
int Depth[N];

void dfs(int n, int par = -1)
{
    for (int cld : g[n])
    {
        if (cld == par)
            continue;
        Depth[cld] = Depth[n] + 1;
        dfs(cld, n);
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
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(1, 0);
    int max_d = -1, max_d_nd;
    for (int i = 1; i <= nd; ++i)
    {
        if (Depth[i] > max_d)
            max_d = Depth[i], max_d_nd = i;
        Depth[i] = 0;
    }

    dfs(max_d_nd);

    int diameter = -1;
    for (int i : Depth)
        diameter = max(diameter, i);

    cout << "Diameter of the tree is " << diameter << endl;
}