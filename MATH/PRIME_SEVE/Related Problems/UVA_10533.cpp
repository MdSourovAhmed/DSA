#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+7;
vector<long long>ans(N,0);
vector<bool> p(N, true);
long long D_s(long long n)
{
	long long s=0;
	while(n){s+=n%10;n/=10;}
	return s;
}

void seve()
{
	p[0]=p[1]=0;
	// P.push_back(2);
	for (long long i = 2; i<=N; i += 1)
	{
		ans[i]=ans[i-1];
		if (p[i])
		{
			if(p[D_s(i)])++ans[i];
			for (long long j = i * i; j <= N; j += i)
			{
				p[j] = false;
			}
		}
	}
}

int main()
{
	seve();
	int n,ind=0;
	cin >> n;
	while (n--)
	{
		int a,b;
		cin>>a>>b;
	// n--;	
		cout << ans[b]-ans[a-1]<< endl;
	}

}
