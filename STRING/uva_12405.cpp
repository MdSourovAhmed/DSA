#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, c = 0;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<char> v(n + 2, '#');
        for (int i = 0; i < n; ++i)
            cin >> v[i];

        int ans = 0;

        for (int i = 0; i < n; ++i)
        {
            if (v[i] == '.')
            {
                ans++;
                i += 2;
            }
        }
        printf("Case %d: %d\n", ++c, ans);
    }
}
