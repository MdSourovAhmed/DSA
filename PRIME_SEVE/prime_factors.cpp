#include <bits/stdc++.h>
using namespace std;
const int N = 1e7;
vector<int> L_p(N, 0), H_p(N, 0);
vector<bool> p(N, true);

void seve()
{
    for (int i = 2; i * i <= N; i += 1)
    {
        if (p[i])
        {
            L_p[i] = H_p[i] = i;
            for (int j = i * 2; j <= N; j += i)
            {
                p[j] = false;
                if (!L_p[j])
                    L_p[j] = i;
                H_p[j] = i;
            }
        }
    }
}

void Prime_factors(int a)
{
    set<int>s;
    int n=a;
    while (a / L_p[a])
    {
        cout << L_p[a] << " ";
        s.insert(L_p[a]);
        a /= L_p[a];
    }
    // cout<<L_p[a];
    // cout<<"There are "<<s.size()<<" prime factors of "<<n<<endl;
}

int main()
{
    seve();
    int t;

    int a;
    cin >> a;
    Prime_factors(a);
}
