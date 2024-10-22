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
    long int n;
    while (scanf("%ld",&n)==1)
    {
        long int m = n, rev = 0;
        while (m)
        {
            rev = (rev * 10) + (m % 10);
            m = m / 10;
        }
        // cout<<n<<" "<<rev;
        if (bts[n])
        {
            if (bts[rev])
            {
                if (rev == n)
                    printf("%ld is prime.\n", n);
                else
                    printf("%ld is emirp.\n", n);
            }
            else
                printf("%ld is prime.\n", n);
        }
        else
        {
            printf("%d is not prime.\n", n);
        }
    }
}