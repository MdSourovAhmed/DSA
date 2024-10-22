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
    string a, b;
    while (getline(cin, a), getline(cin, b))
    {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        for (int i = 0, j = 0;;)
        {
            if (i == a.size() || j == b.size())
                break;
            if (a[i] == b[j])
            {
                cout << a[i];
                // m.erase(c);
                i++;
                j++;
            }
            else if (a[i] > b[j])
                j++;
            else
                i++;
        }

        cout << endl;
    }
}