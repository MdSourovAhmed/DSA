#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 9;
vector<int> g[N];
bool vis[N], col[N];
bool isBipartrite(int v, int c)
{
    vis[v] = 1;
    col[v] = c;
    for (int cld : g[v])
    {
        if (!vis[cld])
        {
            if (!isBipartrite(cld, c ^ 1))
                return false;
        }
        else
        {
            if (col[v] == col[cld])
                return false;
        }
    }
    return true;
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

    bool ans = isBipartrite(1, 0);
    cout << (ans ? "is Bipartrite.\n" : "isn't Bipartrite.\n");

    return 0;
}
