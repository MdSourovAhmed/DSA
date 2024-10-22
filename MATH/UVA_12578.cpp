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
#include<stdlib.h>
typedef long long ll;
const ll N=1e7;
const ll MOD=1e9+7;
using namespace std;
int main()
{
int t;
cin>>t;
while (t--)
{
    int l;
    cin>>l;
    double w=(l/10.0)*6.0,r=l/5.0;
    double C_A=M_PI*r*r,R_A=(l*w-C_A);
    printf("%0.2lf %0.2lf\n",C_A,R_A);
}

}