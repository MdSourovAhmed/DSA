#include <bits/stdc++.h>
using namespace std;

int main()
{
    int c, t = 1;
    while (cin >> c)
    {
        vector<string> S;
        map<string, int> m;
        for (int i = 0; i < c; ++i)
        {
            string s;
            cin >> s;
            S.push_back(s);
            m[s] = 0;
        }

        while (c--)
        {
            string s;
            cin >> s;
            int money;
            cin >> money;
            int n_frinds;
            cin >> n_frinds;
            if (!n_frinds)
                continue;
            int each_money = (money / n_frinds);

            m[s] -= (each_money * n_frinds);

            for (int i = 0; i < n_frinds; i++)
            {
                string s;
                cin >> s;
                m[s] += each_money;
            }
        }
        if (t++>1)
            cout << endl;
        for (auto a : S)
            cout << a << " " << m[a] << endl;
        // m.clear();
    }
}