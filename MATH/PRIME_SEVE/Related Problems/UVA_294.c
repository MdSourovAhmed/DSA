#include<stdio.h>
typedef long long ll;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll L,R;
	    scanf("%lld %lld",&L,&R);

	    int cnt=0;
	    ll mx=-1,n;

	    ll i=L;
	    while(i<=R)
	    {
	    	for(int j=1;j*1ll*j<=i;++j)
	    	{
	    		if(i%j==0)cnt+=2;
	    		if(j*j==i)cnt--;
	    	}

	    	if(mx<cnt){n=i;mx=cnt;}
	    	cnt=0;
	    	i++;
	    }
	    printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",L,R,n,mx );

	}
}

