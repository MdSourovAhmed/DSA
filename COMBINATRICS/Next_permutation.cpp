#include <bits/stdc++.h>
using namespace std;
void Swap(string &s, int f, int l)
{
    char c = s[f];
    s[f] = s[l];
    s[l] = c;
}
void Rev(string &s, int f, int l)
{
    while (l > f)
    {
        Swap(s, f, l);
        f++;
        l--;
    }
}
int main()
{
    string s, a;
    while ((cin >> s) && s != "#")
    {
        a = s;
        Rev(a, 0, s.size() - 1);
        // cout << s << endl;
        int p, q, i = s.size() - 2;

        while (i >= 0 && s[i] >= s[i + 1])
        {
            i--;
        }
        q = s.size() - 1;
        if (i >= 0)
        {
            while (s[q] <= s[i])
            {
                q--;
            }
            Swap(s, i, q);
        }
        q = s.size() - 1;
        Rev(s, i + 1, q);

        (s == a) ? cout << "No Successor\n" : cout << s << endl;
    }
    return 0;
    // cout << s << endl;
    // Rev(s, 0, s.size() - 1);
    // cout << s << endl;
}