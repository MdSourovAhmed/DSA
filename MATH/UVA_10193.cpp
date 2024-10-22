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

ll convert(string &a)
{
    ll s = 0, i = 0;
    reverse(a.begin(), a.end());
    for (char &c : a)
    // s = s * 2 + c - '0';
    {
        s += ((1 << i) * (c - '0'));
        i++;
    }

    return s;
}

int main()
{
    int t, c = 0;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        ll x = convert(a);
        ll y = convert(b);

        printf("Pair #%d: ", ++c);

        if (__gcd(x, y) == 1)
            printf("Love is not all you need!\n");
        else
            printf("All you need is love!\n");
    }
}