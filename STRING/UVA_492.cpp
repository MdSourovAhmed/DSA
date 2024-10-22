
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll N = 1e7 + 7;
// bitset<N> bts;
map<char, bool> m = {{'a', 1}, {'e', 1}, {'i', 1}, {'o', 1}, {'u', 1}, {'A', 1}, {'I', 1}, {'O', 1}, {'U', 1}, {'E', 1}};
vector<char> ans;
bool latter(char c)
{
    return (c>='a'&&c<='z')||(c>='A'&&c<='Z');
}
int main()
{
    string s;
    while (getline(cin, s))
    {
        for (int i = 0; s[i]; i++)
        {
            char c=s[i];
            if (latter(c))
            {
                char ch = c;
                if (m[ch])
                    cout << ch;

                i++;
                for (; s[i] && latter(s[i]); ++i)
                    cout << s[i];
                if (!m[ch])
                    cout << ch;
                cout << "ay";
                i--;
            }
            else
                cout << c;
        }
        cout << endl;
        //     if(c=='.')yes=true;
        //     if (c == ' '||c=='.')
        //     {
        //         ans.push_back(a);
        //         a = "";
        //     }
        //     else
        //         a += c;
        // }
        // if (a.size())
        //     ans.push_back(a);
        // int l=1;
        // for (string &c : ans)
        // {
        //     string b = "";
        //     if (m[c[0]])
        //         b += (c + "ay");
        //     else
        //     {
        //         string d = "";
        //         d.push_back(c[0]);
        //         b += (c.substr(1) + d + "ay");
        //     }
        //     cout << b;
        //     if(ans.size()!=l)cout<<" ";
        //     l++;
        // }
        // if(yes)cout<<".";
        // cout<<endl;

        // ans.clear();
        for (char &c : ans)
            cout << c;
    }
}