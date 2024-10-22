#include <bits/stdc++.h>
using namespace std;
const int N = 1e7+7;


int main()
{
	int a,b;
	cin>>a;
	while (a--)
	{
		int n;
		cin>>n;
		if(n==1){cout<<1<<endl;continue;}
		multiset<int>s;
		int i=9;
	    while(i>1)
		{
			while(n%i==0)
			{s.insert(i);n/=i;}
			i--;
		}

		if(n>9){cout<<-1<<endl;continue;}
		for(auto &x:s)
		cout<<x;
	cout<<endl;
		
	}

}
