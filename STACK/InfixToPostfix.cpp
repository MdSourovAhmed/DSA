#include <bits/stdc++.h>
using namespace std;

int precedence(char a)
{
    if (a == '+' || a == '-')
        return 1;
    if (a == '*' || a == '/')
        return 2;
    if (a == '^')
        return 3;
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s="", ans = "";
        char ch;
        cin>>s; 
        // while(scanf("%c",&ch)==1){s+=ch;}
        stack<char> st;
        for (char &c : s)
        {
            if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
            {
                while (!st.empty() && precedence(st.top()) >= precedence(c))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(c);
            }
            else if (c == '(')
                st.push(c);
            else if (c == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                if (!st.empty())
                    st.pop();
            }
            else
                ans += c;
        }
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        cout << ans << endl;
        // while(!st.empty()){cout<<st.top();st.pop();}
    }
}