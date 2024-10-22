#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e7 + 1;
vector<int> P_i(N);
void P_I()
{
    for (int i = 3; i <= N; ++i)
        P_i[i] = i;
    for (int i = 3; i * i <= N; ++i)
    {
        if (P_i[i] == i)
        {
            P_i[i] -= 1;
            for (int j = i * 2; j <= N; j+=i)
                P_i[j] -= (j / i);//P_i[j]/=i;P_i[j]*=(i-1)///same they are
        }
    }
}

int main()
{
    int a, b;
    cin >> a;
    P_I();
    cout<<P_i[a]<<endl;
}