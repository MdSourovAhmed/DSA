
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
map<string, int> m;
vector<int> Sz(5001,0);
int ans=1;
vector<int> par(5001);
void make(int v)
{
    par[v] = v;
    Sz[v] = 1;
}

int find(int v)
{
    if (v == par[v])
        return v;
    return par[v] = find(par[v]);
}

void Union(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (Sz[a] < Sz[b])
            swap(a, b);
        par[b] = a;
        Sz[a] += Sz[b];
        ans=max(ans,Sz[a]);
    }
}

int main()
{
    int a, b,t;cin>>t;
    while (t--)
    {
        cin>>a;
        int l=1;
        while (a--)
        {
            string s;
            cin >> s;
            m[s] = l;
            make(l);
            l++;
        }
        while (a--)
        {
            string s1, s2;
            cin >> s1 >> s2;
            int p = m[s1], q = m[s2];
            Union(p, q);
        }
        // sort(Sz.begin(), Sz.end());
        // cout << Sz.back() << endl;
        // int ans = 0;                 //they work too;
        // for (int i = 1; i <= p; ++i)
        //     ans = max(ans, Sz[i]);
        cout << ans << endl;
        par.clear();
        m.clear();
        Sz.clear();
        Sz.resize(5001,0);
        ans=1;
    }
}