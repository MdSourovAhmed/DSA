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
const ll N = 10007;
const ll MOD = 1e9 + 7;
using namespace std;
int main()
{
    int v[N];
    for (int i = 1; i < N; ++i)
    {
        int j = (sqrt(i));
        if (j * j == i)
            v[i] = 1;
        else
            v[i] = i;
    }
    for (int i = 2; i < N; ++i)
    {

        if (v[i] == 1)
            continue;
        for (int j = 1; j * j < i; ++j)
        {
            v[i] = min(v[i], (1 + v[i - j * j]));
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << v[n] << endl;
    }
}