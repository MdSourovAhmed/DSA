#include <bits/stdc++.h>
using namespace std;
const int N = 1e7;
const int m = 11;
string s;
int main()
{
    while (true)
    {
        cin >> s;
        if (s[0] == '0' && s.size() == 1)
            return 0;
        int car = 0, r;
        for (int i = 0; s[i]; ++i)
        {
            r = car * 10 + s[i] - '0';
            car = r % m;
        }

        if (!car)
            cout << s << " is a multiple of 11." << endl;
        else
            cout << s << " is not a multiple of 11." << endl;
    }
}