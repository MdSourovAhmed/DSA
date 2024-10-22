#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        int n;
        cin >> n;
        cin.ignore();
        vector<int> v(128, 0);
        while (n--)
        {
            int val;
            char c;
            cin >> c >>v[c];
        }
        cin.ignore();
        cin >> n;
        cin.ignore();
        int money = 0;
        while (n--)
        {
            string s;
            s.reserve(10000);
            getline(cin, s);
            for (char &c : s)
            {
                if (c >= 0 && c <= 128)
                    money += (v[c]);
            }
        }
        // money /= 100.0;
        // printf("%0.2lf$\n",money);
        cout << setprecision(2) << fixed << (double)(money / 100.0) << "$\n";
    }
}