#include <bitset>
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll N=1e7+7;
bitset<N>bts;
bitset<N>tuch;
vector<int>mu(N,0);
void seve()
{
    bts.set();
    for(int i=0;i<N;++i)tuch[i]=0;
    mu[1]=1;
    bts[0]=bts[1]=0;
    for(int i=2;i<N;++i)
    {
        if(bts[i])
        {
            mu[i]++;
            for(ll j=i*2;j<N;j+=i)
            {
                int s_p=i*i;
                if((j%s_p)==0){mu[j]=0;tuch[j]=1;}
                if(!tuch[j])mu[j]++;
                bts[j]=0;
                
            }
        }
    }
}

int main()
{
    seve();
    int n, p;
   
   vector<int>MU(N);
   MU[1]=1;
   for(int i=2;i<mu.size();++i)
   {
    if(!mu[i]){MU[i]=MU[i-1];continue;}
    if(mu[i]&1)mu[i]=-1;
    else mu[i]=1;
    MU[i]=(MU[i-1]+mu[i]);
   }

   while(cin>>n,n)
   {
    printf("%8d%8d%8d\n",n,mu[n],MU[n]);
   }
}