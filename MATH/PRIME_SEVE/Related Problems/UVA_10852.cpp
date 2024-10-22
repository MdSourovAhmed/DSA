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
			P.push_back(i);
			for (int j = i * 2; j <= N; j += i)
			{
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
		int a;
		cin >> a;
		int ind = a;
		ind=0;
		while (ind<a)
		{
			if(p[ind]&&ind*2>a)break;

			ind++;
		}
		cout << ind << endl;
	}

	
}
