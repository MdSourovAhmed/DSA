#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e7;
const ll Mod = 1e7 + 9;
vector<int> g[N];
vector<int> r_g[N];
bool vis[N];
stack<int> st;

void reset_vis()
{
    memset(vis, 0, sizeof(vis));
}

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

void rev_dfs(int v)
{
    vis[v] = 1;
    cout << v << " ";
    for (int child : r_g[v])
    {
        if (vis[child])
            continue;
        rev_dfs(child);
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
    }

    // Applying dfs to stack up the nodes
    for (int i = 1; i <= nd; ++i)
    {
        if (vis[i])
            continue;
        dfs(i);
    }

    // Transpose the graph
    for (int i = 1; i <= nd; ++i)
        for (auto it : g[i])
            r_g[it].push_back(i);

    // Reset the visited array
    reset_vis();

    // Apply dfs in reverse graph untill the stack is empty
    // and printing the strongly connected components(SCC)
    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        if (vis[top])
            continue;
        cout << "SCC: ";
        rev_dfs(top);
        cout << endl;
    }
    return 0;
}
