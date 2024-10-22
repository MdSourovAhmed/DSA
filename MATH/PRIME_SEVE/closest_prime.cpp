#include <bits/stdc++.h>
using namespace std;
const int N = 1e7;
vector<int> P,fst_p(N),last_p(N);
vector<bool> p(N, true);

void seve()
{
	// P.push_back(2);
	for (int i = 2; i * i <= N; i += 1)
	{
		if (p[i])
		{
			// P.push_back(i);
			for (int j = i * 2; j <= N; j += i)
				p[j] = false;
		}
	}
}

int main()
{
	seve();
    int fst,lst;
    for(int i=2;i<N;++i)
    {
        if(p[i])fst=i;
        fst_p[i]=fst;
    }

    for(int i=N-1;i>=2;--i)
    {
        if(p[i])lst=i;
        last_p[i]=lst;
    }
	// for (int &p : P)
	// cout << p << " ";

	// cout << endl;
	// cout<<P.size();

    int t;cin>>t;
    while (t--)
    {
        int a;cin>>a;
        cout<<fst_p[a]<<" "<<last_p[a]<<endl;
    }
    
}
