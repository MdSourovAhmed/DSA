#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 9;
const long long M = 1e9 + 7;
vector<int> g[N];
int Wgt[N];
int Subtree_sum[N];

void dfs(int n, int par = -1)
{
    Subtree_sum[n] += Wgt[n-1]; // as Wgt vector is 0 indexed
    for (int cld : g[n])        // and nodes started from 1
    {
        if (cld == par)
            continue;
        dfs(cld, n);
        Subtree_sum[n]+=Subtree_sum[cld];
    }
}


int main()
{
    int nd, edg;
    cout<<"Enter number of nodes and edges: ";
    cin >> nd >> edg;
    cout<<"Intput the weights of the nodes: ";
    for(int i=1;i<=nd;++i)cin>>Wgt[i];
    int eg = edg;
    cout<<"Enter edges: \n";
    while (eg--)
    {
        int v1, v2, w;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    dfs(1);

    long long Ans=-1;
    for(int i=2;i<=nd;++i)
    {
        int sum1=Subtree_sum[i];
        int sum2=Subtree_sum[1]-sum1;
        Ans=max(Ans,(sum1*1ll*sum2)%M);
    }

    cout<<Ans;
   
}