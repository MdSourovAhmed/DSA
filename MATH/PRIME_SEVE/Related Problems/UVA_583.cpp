#include <iostream>
#include <vector>
using namespace std;
const int N = 1e7;
vector<int>P;
vector<bool> p(N, true);

void seve()
{

    for (long long i = 2; i<= N; i += 1)
    {

        if (p[i])
        {
            P.push_back(i);
            // L_p[i] = H_p[i] = i;
            for (long long j = i * i; j <= N; j += i)
            {
                p[j] = false;
                // if (!L_p[j])
                //     L_p[j] = i;
            }
        }
    }

}

int main()
{
    seve();
    long long a;
    while(cin >> a)
    {   
        if(!a)return 0;
        printf("%lld =", a);
        if(a==1){printf(" %lld\n", a);continue;}
        vector<long long>ans;

        if(a<0){ans.push_back(-1);a*=-1;} 

        int i=0;
        while((P[i]*1ll*P[i])<=a)
        {
            while(a%P[i]==0)
           {
            ans.push_back(P[i]);
            a/=P[i];
            }
        i++;
        }

        if(a>1)ans.push_back(a);

       
        printf(" %lld",ans[0]);
        for (int i = 1;i<ans.size(); i++)
        {
            printf(" x %lld", ans[i]);
            // if(i<ans.size()-1)printf(" x");
        }
        cout<<endl;
    }
   
    return 0;
}
