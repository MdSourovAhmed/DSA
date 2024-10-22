#include <bits/stdc++.h>
using namespace std;
 const double pi = acos(-1);

int main()
{
    double m,n;
    char s[10];
    while(scanf("%lf %lf",&m,&n)==2)
    {
       scanf("%s",&s);
        if(s[0] == 'm')
            n /= 60;
        if(n > 180)
            n = 360-n;
       double ans1,ans2;
       int r=6440+m;
       double ang=n*pi/180; 
       ans1=r*ang;
       ans2=2*r*sin(ang/2);
       printf("%0.6lf %0.6lf\n",ans1,ans2);         
    }
   
    return 0;
}
