#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+7;
vector<long long>P_f(N,0);
vector<bool> p(N, true);

void seve()
{
	p[0]=p[1]=0;
	// P.push_back(2);
	for (long long i = 2; i<=N; i += 1)
	{
		// P_f[i]=P_f[i-1];
		if (p[i])
		{
            P_f[i]++;
			for (long long j = i * 2; j <= N; j += i)
			{
				p[j] = false;
                P_f[j]++;
			}
		}
	}
}

int main()
{
	seve();
	int n,ind=0;
	
	while (cin >> n)
	{
		int a,b;
		// cin>>a;
		cout <<P_f[n]<< endl;
	}

}
