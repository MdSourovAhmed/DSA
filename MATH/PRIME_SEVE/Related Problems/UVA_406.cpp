#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+7;
vector<long long>P;
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
            // P_f[i]++;
            P.push_back(i);
			for (long long j = i * 2; j <= N; j += i)
			{
				p[j] = false;
                // P_f[j]++;
			}
		}
	}
}

int main()
{
	P.push_back(1);
	seve();
	int a,b;
	
	while ((cin >> a>>b))
	{
		int i=0;
		while(P[i]<=a)i++;
		int h,l;
		if((i&1)){l=i/2-b+1;h=l+2*b-1;}
		else {l=i/2-b; h=l+2*b;}

		if(l<0)l=0;
		if(h>=i)h=i;
		
		printf("%d %d:",a,b);
		
		for(i=l;i<h;++i)
			cout<<" "<<P[i];
		cout<<endl<<endl;
	}

}
