#include <bits/stdc++.h>
using namespace std;
const int N = 20000010;
vector<int>ans(N);
vector<bool> p(N, true);

void seve()
{
	p[0]=p[1]=0;
	// P.push_back(2);
	for (int i = 2; i*i<=N; i += 1)
	{
		if (p[i])
		{
			// ans[i]=i;
			// P.push_back(i);
			for (int j = i * 2; j <= N; j += i)
			{
				p[j] = false;
				// P.push_back(i);
			}
		}
	}
}

int main()
{
	seve();
	int n,ind=0;
	// cin >> n;
	for(int i=0;i<N;++i)
	{
		if(p[i]&&p[i+2])ans[ind++]=i;
	}
	while (cin>>n)
	{
	n--;	
		cout <<"("<< ans[n]<<", "<<ans[n]+2<<")" << endl;
	}

}
