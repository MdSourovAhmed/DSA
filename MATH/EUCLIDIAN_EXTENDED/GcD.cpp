#include<bits/stdc++.h>
using namespace std;

int GcD(int a,int b)
{
    if(!b)return a;
    return GcD(b,a%b);
}

int main()
{
    int a,b;
    cin>>a>>b;
    cout<<GcD(a,b);
}