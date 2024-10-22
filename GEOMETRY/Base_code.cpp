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

struct P
{
    int x, y;
    void read() { cin >> x >> y; }
    //    we don't wanna change values hence, making it const
    // using & to speed up the calculation
    P operator-(const P &a) const { return P{x - a.x, y - a.y}; }
    void operator-=(const P &a)
    {
        x -= a.x;
        y -= a.y;
    }
    ll operator*(const P &a) const { return (x * 1ll * a.y) - (y * 1ll * a.x); }

    ll triangle(P &a, P &b)
    {
        return (a - *this) * (b - *this);
    }
};

int main()
{
    P p1, p2, p3;
    p1.read();
    p2.read();
    p2 -= p1;
    p3.read();
    p3 -= p1;
    ll cross_product = p2 * p3;
    // cout << cross_product << endl;
    cout << p1.triangle(p2,p3) << endl;
}