#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e7;
const ll Mod = 1e7 + 9;
vector<int> g[N], topo;
stack<int> st;
bool vis[N];

void dfs(int v)
{
    vis[v] = 1;
    for (int child : g[v])
    {
        if (vis[child])
            continue;
        dfs(child);
    }
    st.push(v);
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
    for (int i = 1; i <= nd; ++i)
    {
        if (vis[i])
            continue;
        dfs(i);
    }

    while (!st.empty())
    {
        int top = st.top();
        topo.push_back(top);
        cout << top << " ";
        st.pop();
    }

    cout << endl;

    for (auto a : topo)
    {
        cout << a << " ";
    }
    return 0;
}

// 5-->0<--4
// 5-->2-->3-->1<--4

// 5 6
// 5 2
// 5 0
// 4 1
// 4 0
// 2 3
// 3 1
// topo sort---> 5 4 0 2 3 1
