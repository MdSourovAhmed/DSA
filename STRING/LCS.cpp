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

int LCS(int m, int n, string &s1, string &s2)
{
    if (m < 0 || n < 0)
        return 0;
    if (dp[m][n] != -1)
        return dp[m][n];
    int ans = LCS(m - 1, n, s1, s2);
    ans = max(ans, LCS(m, n - 1, s1, s2));
    ans = max(ans, LCS(m - 1, n - 1, s1, s2) + (s1[m] == s2[n]));
    return dp[m][n] = ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    string s1, s2;
    cin >> s1 >> s2;
    // int a=LCS(s1.size() - 1, s2.size() - 1, s1, s2);
    string ans = "";
    for (int i = 0; i <= s1.size(); ++i)
    {
        for (int j = 0; j <= s2.size(); ++j)
        {
            if (!j || !i)
            {
                dp[i][j] = 0;
                continue;
            }
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                // if(dp[i-1][j]>dp[i][j-1]){dp[i][j]=dp[i-1][j]}
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int m = s1.size();
    int n = s2.size();
    while (n > 0 && m > 0)
    {
        if (s1[m-1] == s2[n-1])
        {
            ans += s1[m-1];
            m--;
            n--;
        }
        else if (dp[m - 1][n] > dp[m][n - 1])
            m--;
        else
            n--;
    }

    reverse(ans.begin(),ans.end());
    cout << ans;
}