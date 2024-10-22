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
#include <stdlib.h>
typedef long long ll;
const ll N = 1e7;
const ll MOD = 1e9 + 7;
using namespace std;

bool bin_srch(int t, vector<int> &v, int l, int r)
{
    while (r >= l)
    {
        int mid = (l + r) / 2;
        if (v[mid] == t)
            return true;
        if (v[mid] > t)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return false;
}

int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> v(n);
        for (int &a : v)
            cin >> a;
        int t;

        cin >> t;
        sort(v.begin(), v.end());
        int x, y, Min = 1e9, l = 0, r = n - 1;
        for (int &a : v)
        {
            int d = t - a;
            l++;
            if (bin_srch(d, v, l, r))
            {
                if (Min>(d-a))
                {
                    x = a,
                    y = d;
                }
            }
        }
       printf("Peter should buy books whose prices are %d and %d.\n\n",x,y);
    }
}