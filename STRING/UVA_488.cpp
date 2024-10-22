// #include <bits/stdc++.h>
// using namespace std;

// bool fl = true;

// void fun(int a, int b)
// {
//     if (fl)
//         b++;
//     if (!b)
//         return;
//     if (!fl)
//         b--;
//     for (int i = 1; i <= b; ++i)
//         cout << b;
//     cout << endl;
//      if (b == a)
//         fl = false;
//     fun(a, b);
// }

// int main()
// {
//     int t;
//     cin>>t;
//     while(t--)
//     {
//         int a, b;
//         cin >> a >> b;
//         for (int i = 0; i < b; ++i)
//         {
//         fun(a, 0);
//         fl=true;
//         }
//     }
// }



#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const string A[] = {"", "1", "22", "333", "4444", "55555", "666666", "7777777", "88888888", "999999999"};
 
 int main()
 {
 	int t;
 	cin>>t;
 	while(t--)
 	{
 		int a,f;
 		cin>>a>>f;
 		string st="";

 			for(int i=1;i<=a;++i)st+=A[i]+"\n";
 			for(int i=a-1;i>0;--i)st+=A[i]+"\n";	
 		while(f--)
 		{
 			cout<<st;
 			if(f)cout<<endl;
 		}
 		if(t)cout<<endl;
 	}

 }
