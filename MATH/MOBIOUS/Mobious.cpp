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
typedef int in;
typedef unsigned long long ull;
const double pi = 2 * acos(0);
#define maxi 40000
#define pf printf
#define sc scanf
#define pb push_back
#define MEM(x, y) (memset((x), (y), sizeof(x)))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define load(array, size)          \
    for (int i = 0; i < size; i++) \
        cin >> array[i];
#define n_l cout << endl
#define clear_data(array) memset(array, 0, sizeof(array))
#define highest_int 2147483647

ll lpf[1000001], mobius[1000001];

void least_prime_factor()
{
    for (int i = 2; i < 1000001; i++)
    {
        if (!lpf[i])
        {
            for (int j = i; j < 1000001; j += i)
            {
                if (!lpf[j])
                    lpf[j] = i;
            }
        }
    }
}

void Mobius()
{
    for (int i = 1; i < 1000001; i++)
    {
        if (i == 1)
            mobius[i] = 1;
        else
        {
            if (lpf[i / lpf[i]] == lpf[i])
                mobius[i] = 0;
            else
                mobius[i] = -1 * mobius[i / lpf[i]];
        }
    }
}

int main()
{
    least_prime_factor();
    Mobius();
    for (int i = 1; i < 30; i++)
        cout <<i<<"--->"<< mobius[i] << endl;
}