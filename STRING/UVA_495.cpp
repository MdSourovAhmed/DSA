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

string sum(string a, string b)
{
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    // cout<<
    string s = "";
    ll i = 0, c = 0;
    while (a[i])
    {
        if (i < a.size())
            c += a[i] - '0';
        if (i < b.size())
            c += b[i] - '0';
        s += ((c % 10) + '0');
        c /= 10;
        i++;
    }
    if (c)
        s += (c+'0');

    reverse(s.begin(), s.end());
    return s;
}

int main()
{
    map<int, string> m;
    m[0] = "0";
    m[1] = "1";
    m[2] = "1";
    int n = 5000;
    for (int i = 3; i <= n; ++i)
        m[i] = sum(m[i - 1], m[i - 2]);
    while (cin >> n)
        cout << "The Fibonacci number for " << n << " is " << m[n] << endl;
}