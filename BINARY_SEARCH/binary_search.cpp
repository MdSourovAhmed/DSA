#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int Binary_Search(vector<int> &v, int t)
{
    int s = 0, e = v.size() - 1, mid;
    while (e >= s)
    {
        mid = (s + e) / 2;
        if (v[mid] == t)
        {
            return mid;
        }
        if (v[mid] > t)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return -1;
}

int main()
{
    int n;
    srand(time(0));
    n = rand() % 15;
    n++;
    vector<int> v;
    for (int i = 0; i < n; i++)
        v.push_back(rand() % 101);

    sort(v.begin(),v.end());    
    int a;
    // a = rand() % 77;
    for (int &i : v)
        cout << i << " ";
    cout << endl;
    cin >> a;
    int ind = Binary_Search(v, a);
    if (ind != -1)
        cout << a << " found at index " << ind+1 << endl;
    else
        cout << a << " was not found\n";
}