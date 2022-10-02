
#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 7;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if ((n & (n - 1)) == 0)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}