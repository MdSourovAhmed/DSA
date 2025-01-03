#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int sz;

void print(auto v)
{
    for (auto a : v)
        cout << a;
    cout << endl;
}

void Shift(int &a, int &b)
{
    a--;
    b--;
}

void Add(vector<int> &Ans, vector<int> &M, int r)
{
    int i = M.size() - 1, c = 0;
    while (i >= 0)
    {
        c += (Ans[r] + M[i]);
        // cout<<Ans[r]<<endl;
        Ans[r] = (c % 2);
        c /= 2;
        i--;
        r--;
    }
}

void bin(int n, vector<int> &a, vector<int> &b)
{
    if (n < 0)
        n *= -1;

    for (int i = 0; i < sz; ++i)
    {
        a.push_back(1 & (n >> i));
        b.push_back(1 ^ (1 & (n >> i)));
    }
    // cout << (1 & (n >> i));
    // b = sum(b, {1});
    int i = 0, c = 1;
    while (i < b.size())
    {
        c += b[i];
        b[i] = c % 2;
        c /= 2;
        i++;
    }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    // print(a);
    // print(b);
}

void The_num(vector<int> &Ans, int a, int b)
{
    reverse(Ans.begin(), Ans.end());
    int Num = 0, i;
    for (i = 0; i < Ans.size(); i++)
        Num += (Ans[i] * (1 << i));

    if (Ans[Ans.size() - 1])
        Num = ((1 << (i)) - Num) * (-1);
    printf("The Product of %d and %d is %d", a, b, Num);
}

int fun(int a, int b) { return max(log2(a), log2(b)); }
int main()
{
    int a, b;
    cin >> a >> b;
    if (a < 0 || b < 0)
    {
        if (a < 0 && b < 0)
            sz = fun(-a, -b);
        else if (a < 0)
            sz = fun(-a, b);
        else
            sz = fun(a, -b);
    }
    else
        sz = fun(a, b);

    sz += 2;
    // cout << sz << endl;
    vector<int> A, B;
    vector<int> C, D;

    bin(a, A, C);
    // cout << endl;
    bin(b, B, D);

    vector<int> Multipicle, Multiplire, Cmp_Multipicle;
    if (a < 0)
    {
        Multipicle = C;
        // print(C);
        Cmp_Multipicle = A;
    }
    else
    {
        Multipicle = A;
        Cmp_Multipicle = C;
    }
    if (b < 0)
        Multiplire = D;
    else
        Multiplire = B;

    print(Multipicle);
    print(Multiplire);

    int i = Multiplire.size() - 1;
    vector<int> Ans(2 * sz, 0);
    int rit = Ans.size() - 1, lft = rit - sz + 1, fl = 0;

    while (i > 0)
    {
        // cout << Multiplire[i] << endl;
        if (Multiplire[i])
            Add(Ans, Multipicle, rit);
        print(Ans);
        fl |= (Multipicle[0] & Multiplire[i]);
        Shift(lft, rit);
        // if (i)
        Ans[lft] = fl;
        print(Ans);
        cout << endl;
        i--;
    }
    print(Cmp_Multipicle);

    if (Multiplire[0])
        Add(Ans, Cmp_Multipicle, rit);
    Shift(lft, rit);
    fl = (Multiplire[0] ^ Multipicle[0]);
    Ans[lft] = fl;

    print(Ans);
    The_num(Ans, a, b);
}