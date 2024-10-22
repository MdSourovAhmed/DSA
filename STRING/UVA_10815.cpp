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
    string s;
    set<string> st;
    while (cin >> s)
    {
        string ss = "";
        for (char &c : s)
        {
            if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')
            {
                if (c >= 'A' && c <= 'Z')
                    c = c - 'A' + 'a';
                ss += c;
            }
            else if (ss != "")
            {
                st.insert(ss);
                ss = "";
            }
        }
        if (ss.size())
            st.insert(ss);
    }
    for (string c : st)
        cout << c << endl;
}