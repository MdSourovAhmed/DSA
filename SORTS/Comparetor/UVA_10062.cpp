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

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
        return a.first > b.first;
    return a.second < b.second;
}

int main()
{
    string s;
    int c = 0;
    while (getline(cin, s))
    {
        if (c)
            cout << endl;
        vector<int> f(128, 0);
        for (int i = 0; s[i]; i++)
            f[s[i]]++;
        vector<pair<int, int>> ans;
        for (int i = 0; i < f.size(); ++i)
            if (f[i])
                ans.push_back(make_pair(i, f[i]));

        sort(ans.begin(), ans.end(), cmp);
        for (auto x : ans)
            cout << x.first << " " << x.second << endl;
        c++;
    }
}