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

void fun(int l, int r, string &s, int &x, int &D)
{
    int d = 0, D_X = 0, sign=1, D_D = 0;
    bool if_d = false;
    for (int i = l; i < r;i++)
    {
        if (s[i] == 'x')
        {
            if (if_d)
                D_X += sign * d;
            else
                D_X += sign;
            d = 0, if_d = false;
            sign = 1;
        }
        else
        {
            if (s[i] == '-')
            {
                if (if_d)
                    D_D += sign * d;
                sign = -1;
                d = 0;
                if_d = false;
            }
            else if (s[i] == '+')
            {
                if (if_d)
                    D_D += sign * d;
                sign = 1;
                d = 0;
                if_d = false;
            }
            else
            {
                d = d * 10 + s[i] - '0';
                if_d = true;
            }
        }
    }
    if(if_d)D_D+=d*sign;

    // cout << D_X << " " << D_D;
    x=D_X;D=D_D;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n_ind = 0;
        for (char &c : s)
            if (c == '=')
                break;
            else
                n_ind++;
        // cout << n_ind;
        int x1, x2, d1, d2;
        fun(0, n_ind, s, x1, d1);
        // cout << endl;
        fun(n_ind + 1, s.size(), s, x2, d2);

         if(x1 == x2 && d1 == d2)
            puts("IDENTITY");
        else if(x1 == x2 && d1 != d2)
            puts("IMPOSSIBLE");
        else
            printf("%d\n", (int)floor((double)(d2-d1)/(x1-x2)));

    }
}