#include <bits/stdc++.h>
using namespace std;
const int N = 1e7;
vector<int> F;
void Multiply(int n)
{
    int in = F.size();
    int car = 0;
    for (int i = 0; i < in; ++i)
    {
        int rem = n * F[i] + car;
        F[i] = rem % 10;
        car = rem / 10;
    }
    while (car)
    {
        F.push_back(car % 10);
        car /= 10;
    }
}

void Facto(int n)
{
    while (n > 1)
    {
        Multiply(n);
        n--;
    }
}

int main()
{
    F.push_back(1);
    int a;
    cin >> a;
    Facto(a);
    for (int x : F)
        cout << x;
}
