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

vector<int> par(N), sz(N, 0);

void make(int i)
{
    par[i] = i;
    sz[i] = 1;
}

int find(int n)
{
    if (par[n] == n)
        return n;
    return par[n] = find(par[n]);
}

void Union(int n, int m)
{
    int a = find(n);
    int b = find(m);
    if (a != b)
    {
        if (sz[a] < sz[b])
            swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
    }
}

int main()
{
    int t;
    cin >> t;
    char c;
    int a, b;
    int n;
    char s[10007];
    bool y=false;
    while (t--)
    {
        scanf("%d\n", &n);
        if(y)n_l;
        y=1;
        for (int i = 1; i <= n; i++)
            make(i);
        int p, q;
        p = q = 0;
        while (gets(s)&&strlen(s))
        {
            sscanf(s,"%c %d %d", &c, &a, &b);

            if (c == 'c')
                Union(a, b);
            else
                (find(a) == find(b)) ? p++ : q++;
        }

        cout << p << "," << q << endl;
    }
}