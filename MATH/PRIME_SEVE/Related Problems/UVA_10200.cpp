#include <iostream>
#include <bits/stdc++.h>
#include<vector>
using namespace std;
const int N = 1e7;
vector<bool> p(N, true);

bool solve(long long n)
{
        if(n%2==0){return false;}
        for(long long j=3;j*1ll*j<=n;j+=2)
            if(n%j==0)
                return false;
        return true;    
}

int main()
{
    int a,b;
    vector<int>ans(1000005,0);

    for(int i=0;i<=10000;++i){
        ans[i+1]=ans[i];
        long long c=i*i+i+41;
        bool fl=solve(c);
        if(fl)ans[i+1]++;
        
    }
    while(scanf("%d %d",&a,&b)==2)
    {
        double f_ans=((double)(ans[b+1]-ans[a])*100.00/(double)(b-a+1));
        printf("%0.2lf\n",f_ans+1e-6);
        
    }

    return 0;
}


// #include<bits/stdc++.h>
// using namespace std;
// int ar[100005];
// bool pr(int n)
//     {
//         if(n%2==0)return false;
//         for(int i=3;i*i<=n;i+=2){
//             if(n%i==0)return false;
//         }
//         return true;
//     }
// void pregen()
//     {
//         ar[0]=0;
//         for(int i=0;i<=10000;i++){
//             ar[i+1]=ar[i];
//             if(pr((i*i)+i+41))
//                 ar[i+1]++;
//         }
//     }
// int main()
//     {
//         //memset(ar,0,sizeof(ar));
//         pregen();
//         //for(int i=0;i<=10000;i++)cout<<i<<" "<<ar[i]<<endl;
//         int a,b,n,t;
//         while(scanf("%d %d",&a,&b)==2){
//             n=b-a+1;
//             t=ar[b+1]-ar[a];
//             //cout<<n<<" "<<t<<endl;
//             double d=(double)t/(double)n;
//             printf("%.2lf\n",d*100.00+1e-6);
//         }
//         return 0;
//     }