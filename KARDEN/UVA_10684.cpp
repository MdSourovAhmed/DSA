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
int main()
{
    int n;
    while (cin >> n && n)
    {
        vector<int> v(n);
        for (int &x : v)
            cin >> x;
        int s = 0;
        int max_s = 0;
        for (int &x : v)
        {
            max_s += x;
            if (max_s<0)
                max_s = 0;
            s = max(s, max_s);
        }
        if (s)
            printf("The maximum winning streak is %d.\n", s);
        else
            printf("Losing streak.\n");
    }
}