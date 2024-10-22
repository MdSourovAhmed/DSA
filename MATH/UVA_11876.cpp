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
const ll N = 1e7 + 7;
const ll MOD = 1e9 + 7;
using namespace std;
vector<int> v(N, 1),dp(N,0);
int main()
{   
    for (int i = 2; i<= N; ++i)
        for (int j = i; j <= N; j += i)
            v[j]++;

    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i <= N; ++i)
        dp[i] = dp[i - 1] + v[dp[i - 1]];

    int t, i = 0;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        printf("Case %d: ",++i);
        int ans=(lower_bound(dp.begin(),dp.end(),a)-dp.begin())-(upper_bound(dp.begin(),dp.end(),b)-dp.begin());
        // int ans=distance(lower_bound(dp.begin(),dp.end(),a),upper_bound(dp.begin(),dp.end(),b));
        cout<<abs(ans)<<endl;
    }
}