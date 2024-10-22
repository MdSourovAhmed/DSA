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
int dp[1005][1005];

int main()
{
    string s1, s2;
    // cin >> s1 >> s2;
    while (getline(cin,s1))
    {
        getline(cin,s2);
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= s1.size(); ++i)
        {
            for (int j = 1; j <= s2.size(); ++j)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        int m = s1.size();
        int n = s2.size();
        cout << dp[m][n] << endl;
    }
}