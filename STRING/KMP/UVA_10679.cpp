//  cout<<(KMP(s1, s2, l, r)?"y":"n");

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

vector<int> lp_arr(1001);
void lps(string &s)
{
    // lp_arr.reserve(s.size());
    int ind = 0;
    for (int i = 1; i < s.size();)
    {
        if (s[i] == s[ind])
        {
            lp_arr[i] = ind + 1;
            i++;
            ind++;
        }
        else
        {
            if (ind)
                ind = lp_arr[ind - 1];
            else
            {
                lp_arr[i] = 0;
                i++;
            }
        }
    }
}


bool KMP(string &s1, string &s2)
{
    bool found = false;
    int i = 0, j = 0;
    while (i < s1.size())
    {
        if (s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j)
                j = lp_arr[j - 1];
            else
                i++;
        }
        if (j == s2.size())
        {
            return true;
            // l = i - s2.size();
            // // r=i;
            // // cout << "found at: " << l << endl;
            // j = lp_arr[j - 1];
        }
    }

    return false;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s1, s2;
        cin >> s1;
        int t;
        cin >> t;
        while (t--)
        {
            cin >> s2;
            lps(s2);
            // int l, r;
            cout << (KMP(s1, s2) ? "y" : "n") << endl;
            lp_arr.clear();
        }
    }
}