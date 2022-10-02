#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 7;

int main()
{
    int n;
    // cin >> n;
    vector<int> v = {1, 0, 7, 2, 5, 3};

    long long b = (1 << v.size());
    set<vector<int>> ans;
    for (long long i = 0; i < b; ++i)
    {
        int lg = log2(i) + 1;
        int s = 0;
        vector<int> tmp;
        string st = "";
        for (int j = 0; j < lg; j++)
        {
            if (i & (1 << j))
            {
                s += v[j];
                tmp.push_back(v[j]);
            }
        }

        ans.insert(tmp);
    }

    for (auto &x : ans)
    {
        for (int i = 0; i < x.size(); ++i)
        {
            cout << x[i] << " ";
        }

        cout << endl;
    }
}
