#include <bits/stdc++.h>
using namespace std;
const int N = 1e7;
vector<int> P, ans(N);
vector<bool> p(N, true);

void seve()
{
	// P.push_back(2);
	for (int i = 2; i < N; i += 1)
	{
		if (p[i])
		{
			ans[i]=i;
			P.push_back(i);
			for (int j = i * 2; j <= N; j += i)
			{
				// if(!ans[j]&&4*i>j)ans[j]=i;
				ans[j]+=i;
				p[j] = false;
				// if(i<j&&i*2>j)ans[j]=i;
			}
		}
	}
}

int main()
{
	seve();
	int n;
	cin >> n;
	while (n--)
	{
		int a,b;
		cin >> a>>b;
		if(!a&&!b)return 0;
		int ind = a;
		ind=0;
		while (a<=b)
		{
			// if(p[ind]&&ind*2>a)break;
            if(p[ans[a]])
			ind++;
			a++;
		}
		cout << ind << endl;
	}

	// for (int &p : P)
	// 	cout << p << " ";

	// cout << endl;
	// cout<<P.size();
}
