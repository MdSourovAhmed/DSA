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
    vector<string> v1, v2;
    cout << 1
         << endl
         << 1 << " " << 1 << endl;

    v1 = {"1", "1"};
    for (int i = 2; i < 204; i++)
    {
        string s;
        for (int j = 0; j <= v1.size(); ++j)
        {
            if (j == v1.size() || !j)
            {
                v2.push_back("1");
                cout << 1;
                if (!j)
                    cout << " ";
                else
                    cout << endl;
            }
            else
            {
                s=sum(v1[j],v1[j-1]);
                cout<<s<<" ";
                v2.push_back(s);
            }
        }
        v1=v2;
        v2.clear();
    }
}