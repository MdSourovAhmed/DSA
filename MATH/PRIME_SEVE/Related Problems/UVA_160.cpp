
#include <bits/stdc++.h>
using namespace std;
const int N = 1e7;
vector<int>P, L_p(N, 0), H_p(N, 0);
vector<bool> p(N, true);

void seve()
{

    for (int i = 2; i * i <= N; i += 1)
    {
        if (p[i])
        {
        	P.push_back(i);
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

int main()
{
    seve();
    int a;
    while(cin >> a)
    {	
    	if(!a)return 0;
    vector<int>ans(10000,0);
    for(int i=2;i<=a;++i)
	{
		int n=i;
		while(n>1)
		{
			ans[L_p[n]]++;
			n/=L_p[n];
		}

	}
	int l=24;
	for(;l>=0;l--)if(ans[l]!=0)break;
	int c=0;
	if(l>=15)c=0;else c=15;

	printf("%3ld! =", a);
        for (int i = 0;i<=l; i++)
        {
            printf("%3ld", ans[P[i]]);
            c++;
            if (c == 15)
                printf("\n%6c",' ');
        }
        cout<<endl;
    }
   
    return 0;
}
