#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <stdio.h>
#include <bitset>
#include <stdlib.h>
typedef long long ll;
const ll N = 1e7;
const ll MOD = 1e9 + 7;
using namespace std;
int main()
{
    string s;
    bool open_quote = true;
    while (getline(cin, s))
    {
        for (char c : s)
        {
            if (c == '"')
            {
                if (open_quote)
                {
                    cout << "``";
                    // open_quote = false;
                }
                else
                {
                    cout << "''";
                    // open_quote = true;
                }

                // we can also use
                open_quote = !open_quote;
                // beside using false or true
                continue;
            }
            cout << c;
        }
        cout << endl;
    }
}