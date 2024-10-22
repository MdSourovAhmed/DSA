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
#include <bitset>
#include <stdlib.h>
typedef long long ll;
const ll N = 1e7;
const ll MOD = 1e9 + 7;
using namespace std;



// .*..***.***.
// .*....*...*.
// .*..***.***.
// .*..*.....*.   // chech this row...if(s[0]=='*')-->1,
// .*..***.***.
                                    //s[i*4]=='*'-->2 and
                                   //s[i*4+2]=='*'-->3



int main()
{
    int t;
    string s;
    cin >> t;
    for (int x : {1, 2, 3, 4})
        cin >> s;

    for(int i=0; i<t; i++)
	{
	    if(s[i*4]=='*') cout<<2;
	    else if(s[i*4+2]=='*') cout<<3;
	    else cout<<1;
	}
	cout<<endl;    
}