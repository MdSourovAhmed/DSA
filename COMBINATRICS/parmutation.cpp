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
vector<char> name;
vector<bool> vis(128);
void parmutation(string &s)
{
    if (name.size() == s.size())
    {
        for (char c : name)
            cout << c;
        cout << endl;
        return;
    }
    for (int j = 0; j < s.size(); ++j)
    {
        if (vis[s[j]])
            continue;
        vis[s[j]] = true;
        name.push_back(s[j]);
        parmutation(s);
        vis[s[j]] = false;
        name.pop_back();
    }
}

int main()
{
    int t = 0;
    string s = "niSma";
    int n = s.size();
    parmutation(s);
}