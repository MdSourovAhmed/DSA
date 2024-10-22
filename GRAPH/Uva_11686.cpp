#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <stdio.h>
#include <bitset>
#include <stdlib.h>
typedef long long ll;
const ll N = 1e7;
const ll MOD = 1e9 + 7;
using namespace std;
typedef int in;
typedef unsigned long long ull;
const double pi = 2 * acos(0);
#define maxi 40000
#define pf printf
#define sc scanf
#define pb push_back
#define MEM(x, y) (memset((x), (y), sizeof(x)))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define load(array, size)          \
    for (int i = 0; i < size; i++) \
        cin >> array[i];
#define n_l cout << endl
#define clear_data(array) memset(array, 0, sizeof(array))
#define highest_int 2147483647

vector<int> ans, indeg(N);
vector<int> g[N];
bool vis[N], vis2[N], fl;

void dfs(int v)
{
    vis[v] = 1;
    vis2[v] = 1;
    for (int a : g[v])
    {
        if (!vis[a])
            dfs(a);
        else if (vis2[a])
            fl = false;
    }
    vis2[v] = 0;
    ans.push_back(v);
}

void topo(int n)
{
    // queue<int,vector<int>> q;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n; ++i)
        if (!indeg[i])
            q.push(i);

    while (!q.empty())
    {
        int t = q.top();
        q.pop();
        ans.push_back(t);
        for (int a : g[t])
        {
            indeg[a]--;
            if (!indeg[a])
                q.push(a);
        }
    }
}

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        fl = true;
        if (!n && !m)
            break;

        for (int i = 0; i < N; ++i)
        {
            g[i].clear();
            indeg[i] = 0;
            vis[i] = 0;
            vis2[i] = 0;
        }
        ans.clear();

        while (m--)
        {
            int x, y;
            cin >> x >> y;
            indeg[y]++;
            g[x].push_back(y);
        }
        for (int i = 1; i <= n; ++i)
            if (!vis[i])
                dfs(i);
        reverse(ans.begin(), ans.end());
        // topo(n);
        // printf("Case #%d: Dilbert should drink beverages in this order:", ++t);
        if (!fl)
            cout << "IMPOSSIBLE\n";
        else
            for (int i : ans)
            {
                cout << i << endl;
            }
    }
    return 0;
}