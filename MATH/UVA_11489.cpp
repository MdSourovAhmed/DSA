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

ll sm = 0;

bool divby3(string &ss)
{
    for (char &c : ss)
        if ((sm - (c - '0')) % 3 == 0)
            return true;
    return false;
}
int divby3cnt(string &s)
{
    int cnt = 0;
    for (char &c : s)
        if ((c - '0') % 3 == 0)
            ++cnt;
    return cnt;
}


char Ans(string &ss)
{
    for (char &c : ss)
        sm += (c - '0');

    if ((sm % 3) == 0)
        return ((divby3cnt(ss) % 2) == 1 ? 'S' : 'T');
    else if (divby3(ss))
        return ((divby3cnt(ss) % 2) == 0 ? 'S' : 'T');
    else
        return 'T';
}

int main()
{
    int t, c = 1;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        if (s.size() == 1)
        {
            printf("Case %d: S\n", c++);
            continue;
        }
        printf("Case %d: %c\n", c++, Ans(s));
        sm=0;
    }
}