#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+7;
vector<long long>ans(N,0);
vector<bool> p(N, true);

void seve()
{
	p[0]=p[1]=0;
	// P.push_back(2);
	for (long long i = 2; i<=N; i += 1)
	{
		// ans[i]=ans[i-1];
		if (p[i])
		{
			ans[i]++;
			for (long long j = i * 2; j <= N; j += i)
			{
				ans[j]++;
				p[j] = false;
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
		if(!n)return 0;
		cout << ans[n]<< endl;
	}

}
