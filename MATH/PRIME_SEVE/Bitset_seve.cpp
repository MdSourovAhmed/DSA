#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e7;
bitset<N> bts;
vector<int> P;
void seve()
{
    bts.set();
    for (ll i = 2; i <= N; ++i)
    {
        if (bts[i])
        {
            P.push_back(i);
            for (ll j = 2 * i; j <= N; j += i)
                bts[j] = 0;
        }
    }
}

int main()
{
    seve();
    ll t;
    while (cin >> t, t)
    {
    //    vector<pair<int,int>>v_p;
        ll c=0;
        for (ll i = 0; P[i] <= t/2; ++i)
            {
                if(bts[t-P[i]])c++;
            }

            cout<<c<<endl;
    }
}
