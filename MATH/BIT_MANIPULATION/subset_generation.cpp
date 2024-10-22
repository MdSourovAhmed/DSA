#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 7;
typedef long long ll;

map<ll, int> A, B;

vector<ll> v(41);

void sub_sets(int &ind, map<ll, int> &m, int a = 0)
{
    ll b = (1 << ind);
    for (ll i = 1; i < b; ++i)
    {
        int lg = log2(i) + 1;
        ll s = 0;
        for (int j = 0; j < lg; j++)
        {
            if (i & (1 << j))
                s += v[j + a];
        }
        m[s]++;
    }
}

int main()
{
    int n, t;
    while (cin >> n >> t)
    {
        for (int i = 0; i < n; ++i)
            cin >> v[i];

        int ind1 = n / 2;
        if (ind1 == 0)
            ind1++;
        int ind2 = n - ind1;
        A.clear();
        sub_sets(ind1, A);
        B.clear();
        sub_sets(ind2, B, ind1);

        ll c = 0;
        for (auto &x : A)
            if (B.count(t - x.first))
                c += (x.second * 1ll * B[t - x.first]);

        cout << c + A[t] + B[t] << endl;
    }
}
