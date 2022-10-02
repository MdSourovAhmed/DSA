#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int partition(int f, int e, vector<int> &v)
{
    // including mid in the left     //right starts from mid+1
    int pivot = v[e];
    int f_i = f;
    for (int i = f; i < e; ++i)
    {
        if (v[i] <= pivot)
        {
            swap(v[i],v[f_i]);
            f_i++;
        }
    }
    swap(v[e],v[f_i]);

    return f_i;
}

void quick_sort(int f, int e, vector<int> &v)
{
    if (f >= e)
        return;
    int pivot = partition(f, e, v);
    quick_sort(f, pivot - 1, v);
    quick_sort(pivot + 1, e, v);
}

int main()
{
    srand(time(0));
    vector<int> v;
    for (int i = 0; i < rand() % 15 + 3; ++i)
    {
        v.push_back(rand() % 121);
    }

    cout << "The array is :\n";
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";

    cout << endl;

    quick_sort(0, v.size() - 1, v);

    cout << "After sorting----: \n";
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";

    cout << endl;
}