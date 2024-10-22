
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include<bitset>
typedef long long ll;
const ll N = 1e7;
const ll MOD = 1e9 + 7;
using namespace std;
vector<int> v(33,0);
bitset<77>bts;
vector<bool> vis(128);

void search(int n,int ind)
{
    if (ind == n-1&&bts[v[n-1]+1])
    {
        cout<<"1";
        for(int i=1;i<n;++i)
            printf(" %d",v[i]);
        cout << endl;
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            if (!vis[i]&&bts[v[ind]+i])
           { 
            vis[i] = true;
            v[ind+1]=i;
            search(n,ind+1);
            vis[i] = false;
            v.pop_back();

            }
        }
    }
}

int main()
{
    bts.set();
    bts[0]=bts[1]=0;
    
    int t=1;
    for(int i=2;i*i<=77;i++)
    {
        if(bts[i])
        {
            for(int j=i*2;j<=77;j+=i)
                bts[j]=0;
        }
    }
    int n;
    while (cin >> n)
    {
        if(t>1)cout<<endl;
        printf("Case %d:\n",t++);
        v[n]=1;
        v[0]=1;
        search(n,0);   
        v.clear(); 
    }
}