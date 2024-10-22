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

map<char, int> m = {{'(', 1}, {')', -1}, {'{', 2}, {'}', -2}, {'[', 3}, {']', -3}};

bool B_paranth(string &s)
{
    stack<char> st;
    // bool ans;
    for (char &c : s)
    {
        if (m[c]>0)
            st.push(c);
        else
        {
            if (!st.empty()&&(m[st.top()] + m[c]) == 0)
            st.pop();
            else st.push(c);    
        }
    }
    return st.empty();
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        getline(cin,s);
        // cin >> s;
        cout << (B_paranth(s) ? "Yes" : "No") << endl;
    }
}