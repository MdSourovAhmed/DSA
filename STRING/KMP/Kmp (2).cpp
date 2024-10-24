#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> lps;
void KMP(string p, string s)
{
    string str = p + '#' + s;
    int len = str.size();
    lps.resize(len, 0);

    for (int i = 1; i < len; ++i)
    {
        int prev_indx = lps[i - 1];
        while (prev_indx && str[i] != str[prev_indx])
            prev_indx = lps[prev_indx - 1];

        lps[i] = prev_indx + (str[i] == str[prev_indx]);
    }
}

int main()
{
    cout << "Enter pattern and a string: ";
    string p, s;
    cin >> p >> s;
    KMP(p, s);
    for (int i : lps)
        cout << i << " ";
}