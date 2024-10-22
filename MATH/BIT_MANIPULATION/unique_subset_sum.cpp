
#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 7;

int main()
{
    int t;
    while (cin >> t)
    {
        if (!t)
            return 0;
        int n;
        cin >> n;
        vector<int> v(n);
        for (int &i : v)
            cin >> i;
        long long b = 1 << n;
        set<vector<int>> ans;
        for (long long i = 0; i < b; ++i)
        {
            int lg = log2(i) + 1;
            int s = 0;
            vector<int> tmp;
            // string st = "";
            for (int j = 0; j < lg; j++)
            {
                if (i & (1 << j))
                {
                    s += v[j];
                    tmp.push_back(v[j]);
                }
            }

            if (s == t)
            {
                sort(tmp.rbegin(), tmp.rend());
                ans.insert(tmp);
            }
        }

        printf("Sums of %d:\n", t);
        if (!ans.size())
        {
            cout << "NONE\n";
            continue;
        }
        vector<vector<int>> vv;
        for (auto &x : ans)
        {
            vv.push_back(x);
        }

        ans.clear();
        sort(vv.rbegin(), vv.rend());

        for (auto &x : vv)
        {
            for (int i = 0; i < x.size(); ++i)
            {
                if (!i)
                    cout << "+";
                cout << x[i];
            }

            cout << endl;
        }
    }
}
