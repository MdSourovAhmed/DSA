#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int i = 0;
    while (t--)
    {
        double ab, ac, bc, ratio;
        cin >> ab >> ac >> bc >> ratio;

        // ratio=(a):(b);
        // for, area(abc)=area(adc)+area(bcde)=area(ax+bx)
        // and as a:b=c then,b=1,a=c or ratio=c;
        // therefore,area(abc)=x(a+b)=x(a+1);
        // for any two identical triangles
        // area(adc):area(abc)=(ad:ab)^2
        // => ax:x(a+1)=(ad:ab)^2

        double ans = sqrt(ratio / (ratio + 1)) * ab;
        printf("Case %d: %0.8lf\n", ++i, ans);
    }
}