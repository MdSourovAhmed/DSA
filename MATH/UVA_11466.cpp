
#include <bitset>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll N = 1e7 + 7;
bitset<N> bts;
vector<ll> P;

void seve()
{
    bts.set();
    bts[0] = bts[1] = 0;
    for (ll i = 2; i < N; ++i)
    {
        if (bts[i])
        {
            P.push_back(i);
            for (ll j = i * 2; j < N; j += i)
                bts[j] = 0;
        }
    }
}

int main()
{
    seve();
    ll n, t;
    // cin.ignore();
    while (cin >> n && n)
    {
        n = abs(n);
        vector<ll> ans;
        for (int i = 0; P[i] * 1ll * P[i] <= n && n > 1; ++i)
        {
            if (n % P[i] == 0)
            {
                while (n % P[i] == 0)
                {
                    n /= P[i];
                }
                ans.push_back(P[i]);
            }
        }
        if (n > 1)
            ans.push_back(n);
        if (ans.size() > 1)
            cout << ans.back() << endl;
        else
            cout << -1 << endl;
        ans.clear();
    }
}
