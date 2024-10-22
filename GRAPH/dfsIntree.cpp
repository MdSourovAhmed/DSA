#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 9;
vector<int> g[N];
vector<int> d(N), h(N);

void dfs(int v, int par)
{
    for (int cld : g[v])
    {
        if (cld == par)
            continue;
        d[cld] = d[v] + 1;
        dfs(cld, v);
        h[v] = max(h[v], h[cld] + 1);
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

    for (int i = 1; i <= nd; ++i)
        cout << d[i] << " " << h[i] << endl;
    return 0;
}
