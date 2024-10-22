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
    int n;
    while (cin >> n)
    {
        int c, v;
        stack<int> stk;
        queue<int> que;
        priority_queue<int> pque;
        int st = 0, qu = 0, pqu = 0, cnt = 0;
        int m = n;
        while (m--)
        {
            cin >> c >> v;
            if (c == 1)
            {
                stk.push(v);
                que.push(v);
                pque.push(v);
                st++;
                qu++;
                pqu++;
            }
            else
            {
                if (!stk.empty() && stk.top() == v)
                {
                    stk.pop();
                    st++;
                }
                if (!que.empty() && que.front() == v)
                {
                    que.pop();
                    qu++;
                }
                if (!pque.empty() && pque.top() == v)
                {
                    pque.pop();
                    pqu++;
                }
            }
        }
        if ((st == n && qu == n) || (st == n && pqu == n) || (pqu == n && qu == n))
            printf("not sure\n");
        else if (pqu != n && qu != n && st != n)
            printf("impossible\n");
        else if (st == n)
            printf("stack\n");
        else if (qu == n)
            printf("queue\n");
        else
            printf("priority queue\n");
    }
}