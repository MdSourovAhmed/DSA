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
    int n;
    while(cin>>n&&n)
    for (int i = 0; P[i]<= n/2; ++i)
        {
            {
                    if(bts[n-P[i]])
                   { printf("%d = %d + %d\n",n,P[i],n-P[i] );break;}
                }
        }

}