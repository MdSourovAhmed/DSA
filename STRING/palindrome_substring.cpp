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
    int l;
    string s;
    cin >> s;
    l = s.size();
    int b_len, l_i;
    for (int i = 0; i < l; ++i)
    {
        for (int j = 0; i - j >= 0 && i + j < l; ++j)
        {
            if (s[i - j] != s[i + j])
                break;
            int len = 2 * j + 1;
            if (len > b_len)
            {
                b_len = len;
                l_i = i + j;
            }
        }
    }
    for (int i = 0; i < l - 1; ++i)
    {
        for (int j = 1; i - j + 1 >= 0 && i + j < l; ++j)
        {
            if (s[i - j + 1] != s[i + j])
                break;
            int len = 2 * j;
            if (len > b_len)
            {
                b_len = len;
                l_i = i + j;
            }
        }
    }

    for (int i = l_i - b_len+1; i <= l_i; ++i)
        cout << s[i];
    cout << endl;
}