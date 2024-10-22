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
bool vis[N];

void dfs(int v)
{
    vis[v] = 1;
    for (int a : g[v])
    {
        if (vis[a])
            continue;
        dfs(a);
    }
    ans.push_back(v);
}

void topo(int n)
{
    // queue<int,vector<int>> q;
    priority_queue<int,vector<int>,greater<int>>q;
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
    int n, t = 0;
    while (cin >> n)
    {
        for (int i = 0; i < N; ++i)
        {
            g[i].clear();
            indeg[i] = 0;
        }

        ans.clear();
        string s;
        map<int, string> a;
        map<string, int> b;
        for (int i = 0; i < n; ++i)
        {
            cin >> s;
            a[i] = s;
            b[s] = i;
        }
        int m;
        cin >> m;
        while (m--)
        {
            string x, y;
            cin >> x >> y;
            indeg[b[y]]++;
            g[b[x]].push_back(b[y]);
        }

        // dfs(1);
        // reverse(ans.begin(), ans.end());
        topo(n);
        printf("Case #%d: Dilbert should drink beverages in this order:", ++t);
        for (int i : ans)
        {
            cout << " " << a[i];
        }
        cout << ".\n\n";
    }
}