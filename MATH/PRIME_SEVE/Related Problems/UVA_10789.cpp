#include <bits/stdc++.h>
using namespace std;
const int N = 1e7;
// vector<int> P, ans(N);
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
				// if(!ans[j]&&4*i>j)ans[j]=i;
				// ans[j]+=i;
				p[j] = false;
				// if(i<j&&i*2>j)ans[j]=i;
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
		string s;
		cin>>s;
		vector<int>v(128,0);
		for(int i=0;i<s.size();++i)
		{
			v[s[i]]++;
		}

		// for(int i=0;i<26;++i)
		// {
		// 	cout<<v[i];
		// }
		// cout<<++i
		printf("Case %d: ",++ind);
		string ans="";
		for(int i=0;i<128;++i)
			if(p[v[i]])
				// cout<<i<<" ";
				ans+=(char)(i);
			if(ans.size()==0)
			ans+="empty";
		cout<<ans<<endl;
		
		// cout << ind << endl;
	}

}
