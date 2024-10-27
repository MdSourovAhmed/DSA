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

class SegTree
{
public:
    int len;
    vector<ll> t, unpropUpd;
    vector<bool> isLazy;
    SegTree() {}
    SegTree(int l)
    {
        len = l;
        t.resize(4 * len);
        unpropUpd.resize(4 * len);
        isLazy.resize(4 * len);
    }

    // void apply(int n, int l, int r, int val)
    // {
    //     if (l != r)
    //     {
    //         isLazy[n] = true;
    //         unpropUpd[n] += val;
    //     }
    //     t[n] += (r - l + 1) * val;
    // }

    // void pushDown(int n, int l, int r)
    // {
    //     if (!isLazy[n])
    //         return;
    //     isLazy[n] = false;
    //     int m = (l + r) / 2;
    //     apply(2 * n, l, m, unpropUpd[n]);
    //     apply(2 * n + 1, m + 1, r, unpropUpd[n]);

    //     unpropUpd[n] = 0;
    // }

    void build(vector<int> &v, int n, int l, int r)
    {
        if (l == r)
        {
            t[n] = v[l];
            return;
        }
        int m = (l + r) / 2;
        build(v, 2 * n, l, m);
        build(v, 2 * n + 1, m + 1, r);
        t[n] = t[2 * n] + t[2 * n + 1];
    }

    int query(int n, int l, int r, int ql, int qr)
    {
        if (l > qr || r < ql)
            return 0;
        if (ql <= l && qr >= r)
            return t[n];
        
        int m = (l + r) / 2;
        ll lqa = query(2 * n, l, m, ql, qr);
        ll rqa = query(2 * n + 1, m + 1, r, ql, qr);
        return lqa + rqa;
    }

    void update(int n, int l, int r, int id, int val)
    {
        if (id > r || id < l)
            return;
        if (l == id && r == id)
        {
            t[n] = val;
            return;
        }

        int m = (l + r) / 2;
        update(2 * n, l, m, id, val);
        update(2 * n + 1, m + 1, r, id, val);
        t[n] = t[2 * n] + t[2 * n + 1];
    }

    void build(vector<int> &v) { build(v, 1, 0, len - 1); }
    int query(int ql, int qr) { query(1, 0, len - 1, ql, qr); }
    void update(int id, int val) { update(1, 0, len - 1, id, val); }
};

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    cout << "The array is...\n";
    for (int &i : v)
        cout << i<<" ";

    SegTree segtree(n);
    segtree.build(v);

    cout << endl;

    for (int i = 0; i < n; ++i)
        cout << segtree.query(i, i) << " ";
    cout << endl;

    ll sum = segtree.query(1, 5);
    cout << "Sum for range 1 to 5 is: " << sum << endl;

    segtree.update(2, 10);

    sum = segtree.query(1, 5);
    cout << "After Updating, sum for range 1 to 5 is: " << sum << endl;

    return 0;
}