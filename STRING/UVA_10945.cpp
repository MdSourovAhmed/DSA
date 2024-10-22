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

bool palin(string &s)
{
    int i = 0, j = s.size() - 1;
    while (j > i)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int main()
{
    string s;
    while (getline(cin, s)&&s != "DONE")
    {
        string b = "";
        for (char &c : s)
        {
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
            {
                if ((c >= 'A' && c <= 'Z'))
                    c = (c - 'A' + 'a');
                b += c;
            }
        }

        cout << (palin(b) ? "You won't be eaten!" : "Uh oh.." )<< endl;
    }
}