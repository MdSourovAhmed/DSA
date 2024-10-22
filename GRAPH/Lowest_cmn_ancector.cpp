#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 9;
vector<int> g[N];
// bool vis[N];
int Par[N];

void dfs(int n, int par = -1)
{
    Par[n] = par; // storing parent for each node
    for (int cld : g[n])
    {
        if (cld == par)
            continue;
        dfs(cld, n);
    }
}

vector<int> getPath(int n) // will return a vector consists of parents of a given node
{
    vector<int> Path;
    while (n != -1)
    {
        Path.push_back(n);
        n = Par[n];
    }

    reverse(Path.begin(), Path.end());
    return Path;
}

int main()
{
    int nd, edg;
    cout<<"Enter number of nodes and edges: ";
    cin >> nd >> edg;
    int eg = edg;
    while (eg--)
    {
        int v1, v2, w;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    dfs(1);

    cout<<"Enter two nodes to find their lowest cmn ancestor: ";
    int x, y; // will find lowest common  ancestor of x and y
    cin >> x >> y;
    vector<int> Path_x = getPath(x);
    vector<int> Path_y = getPath(y);

    int ln = min(Path_x.size(), Path_y.size());

    int Ans = -1;

    for (int i = 0; i < ln; ++i)
    {
        if (Path_x[i] == Path_y[i])
            Ans = Path_x[i];
        else
            break;
    }

    cout << "Lowest common ancestor of " << x << " and " << y << " is " << Ans << endl;
}