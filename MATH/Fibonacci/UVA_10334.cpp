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
#include<stdio.h>
#include<bitset>
#include<stdlib.h>
typedef long long ll;
const ll N=1e3+7;
const ll MOD=1e9+7;
using namespace std;

vector<string>v(N);
string sum(string a, string b)
{
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    // cout<<
    string s = "";
    ll i = 0, c = 0;
    while (a[i])
    {
        if (i < a.size())
            c += a[i] - '0';
        if (i < b.size())
            c += b[i] - '0';
        s += ((c % 10) + '0');
        c /= 10;
        i++;
    }
    if (c)
        s += (c+'0');

    reverse(s.begin(), s.end());
    return s;
}

int main()
{
    v[0]="1";
    v[1]="2";
    for(int i=2;i<1007;++i)
    v[i]=sum(v[i-1],v[i-2]);
    int n;
    while(cin>>n)
    {
        cout<<v[n]<<endl;
    }

}