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

void seg_seve(ll l, ll h)
{
    if (l == 1)
        l++;
    vector<bool> seg_v(h - l + 1, 1);
    for (ll i = 0; P[i] * P[i] <= h; i++)
    {
        ll C_p = P[i];
        ll base = (l / C_p) * C_p;
        if (base < l)
            base += C_p;
        for (ll j = base; j <= h; j += C_p)
        {
            seg_v[j - l] = 0;
        }
        if (base == C_p)
            seg_v[base - l] = 1;
    }

    for (int i = 0; i < seg_v.size(); ++i)
    {
        if (seg_v[i])
            cout << i + l << " ";
    }
}

int main()
{
    seve();
    ll lo, hi;
    cin >> lo >> hi;
    seg_seve(lo, hi);
}