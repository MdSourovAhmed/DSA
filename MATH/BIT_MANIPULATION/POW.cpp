#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e9 + 7;
ll Pow(int a, int b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans *= a;
            ans %= M;
        }
        a *= a;
        a %= M;
        b >>= 1;
    }
    return ans;
}

int main()
{
    int n, p;
    cin >> n >> p;
    cout << 1ll * Pow(n, p);
}