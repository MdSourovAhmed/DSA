#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        if (!n)
            return 0;
        int ind = log2(n);
        // for(int i=ind;i>=0;--i)
        // cout<<(1&(n>>i));
        int sum = 0, c = 0;
        for (int i = 0; i <= ind; i++)
        {
            // cout << (1 & (n >> i));
            if (1 & (n >> i))
            {
                c++;
                if (c & 1)
                    sum += (1 << i);
            }
        }
        // cout << sum << " " << n - sum << endl;
        cout<<sum<<" "<<(n^sum)<<endl;
    }
}