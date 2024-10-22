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
#include <stdlib.h>
typedef long long ll;
const ll N = 1e7;
const ll MOD = 1e9 + 7;
using namespace std;
int main()
{
    string str[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

    map<string, int> mp;
    int ind = 1;
    for (int i = 0; i <= 25; i++)
    {
        mp["" + str[i]] = ind++;
    }

    for (int i = 0; i <= 25; i++)
        for (int j = i + 1; j <= 25; j++)
            mp["" + str[i] + str[j]] = ind++;

    for (int i = 0; i <= 25; i++)
        for (int j = i + 1; j <= 25; j++)
            for (int k = j + 1; k <= 25; k++)
                mp["" + str[i] + str[j] + str[k]] = ind++;

    for (int i = 0; i <= 25; i++)
        for (int j = i + 1; j <= 25; j++)
            for (int k = j + 1; k <= 25; k++)
                for (int l = k + 1; l <= 25; l++)
                    mp["" + str[i] + str[j] + str[k] + str[l]] = ind++;

    for (int i = 0; i <= 25; i++)
        for (int j = i + 1; j <= 25; j++)
            for (int k = j + 1; k <= 25; k++)
                for (int l = k + 1; l <= 25; l++)
                    for (int m = l + 1; m <= 25; m++)
                        mp["" + str[i] + str[j] + str[k] + str[l] + str[m]] = ind++;
    string s;
    while (cin >> s)
    {   
        cout << mp[s] << endl;
    }
}