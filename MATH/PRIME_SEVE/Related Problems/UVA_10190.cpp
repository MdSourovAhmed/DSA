
#include <iostream>
#include<cmath>
#include <vector>
using namespace std;

int main()
{
    int m,n;
    while(cin>>m>>n)
    {
        if(n<2||m==0||m<n){cout<<"Boring!\n";continue;}
        int fl=0;  
        vector<int>v(1000,m);
        for(int i=1;;++i){
            if(v[i-1]==1)break;
            if(v[i-1]%n){fl=-1;break;}
            v[i]=v[i-1]/n;
        }

        if(fl<0){puts("Boring!");continue;}
        printf("%d",v[0]);
        for(int i=1;v[i]<m;++i)
            cout<<" "<<v[i];
        cout<<endl;
    }
   
    return 0;
}
