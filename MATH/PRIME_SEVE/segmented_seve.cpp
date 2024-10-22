#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e7;
bitset<N> bts;
vector<int> P;
void seve()
{
    bts.set();
    for (ll i = 2; i * i <= N; ++i)
    {
        if (bts[i])
        {
            P.push_back(i);
            for (ll j = 2 * i; j <= N; j += i)
            {
                bts[j] = 0;
            }
        }
    }
}

void segmnt_seve(ll a, ll b)
{
    vector<bool> seg_v(b - a + 1, 1);
    for (ll i = 0; P[i] * P[i] <= b; i++)
    {
        int c_p = P[i];
        int base = (a / c_p) * c_p;
        if (base < a)
            base += c_p;
        for (ll j = base; j <= b; j += c_p)
        {
            seg_v[j - a] = 0;
        }
        if (c_p == base)    //if n is itself prime, mark it true
            seg_v[base - a] = 1;
    }

    for (int i = 0; i <= b - a; ++i)
    {
        if (seg_v[i])
            cout << i + a << " ";
    }
}

int main()
{
    seve();
    ll a, b;
    cin >> a >> b;
    segmnt_seve(a, b);
    // for (int i = 0; i < b; ++i)
    // cout << P[i] << " ";
}