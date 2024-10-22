#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 1e9+7;
ll Pow(int a, int b)
{
    if (!b)
        return 1;
    ll ans = Pow(a, b >> 1);
    ans %= M;
    a %= M;
    if (b & 1)
        return a *= ((ans * ans) % M);
    return a = (ans * ans) % M;
}

int main()
{
    int n, p;
    cin >> n >> p;
    cout << 1ll * Pow(n, p);
}