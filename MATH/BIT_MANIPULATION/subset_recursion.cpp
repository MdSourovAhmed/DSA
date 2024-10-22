#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 7;
set<vector<int>> ans;
vector<int> v;

void subset(int i, vector<int> &tmp,int t)
{
    if (i == v.size())
    {
        return;
    }
    // if ()
        tmp.push_back(v[i]);
    subset(i + 1, tmp,t);
    tmp.pop_back();
    subset(i + 1, tmp,t);
    // tmp.push_back(v[i+1]);
}

int main()
{
    int t;
    // while (cin >> t)
    // {
        // if (!t)
        //     return 0;
        int n;
        cin >> n;
        cin >> t;
        vector<int> v(n);
        for (int &i : v)
            cin >> i;
        vector<int> tmp;
        subset(0, tmp,t);

        for (auto &x : ans)
        {
            for (int i = 0; i < x.size(); ++i)
            {
                cout << x[i] << " ";
            }

            cout << endl;
        }
    // }
}

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e7 + 7;
// set<vector<int>> ans;
// vector<int> v = {1, 0, 7, 2, 5, 3};

// void subset(int i, vector<int> &tmp)
// {
//     if (i == v.size())
//        { ans.insert(tmp);return;}
//     tmp.push_back(v[i]);
//     subset(i+1, tmp);
//     tmp.pop_back();
//     subset(i + 1, tmp);
//     // tmp.push_back(v[i+1]);
// }

// int main()
// {
//     int n;
//     vector<int> tmp;
//     subset(0, tmp);

//     for (auto &x : ans)
//     {
//         for (int i = 0; i < x.size(); ++i)
//         {
//             cout << x[i] << " ";
//         }

//         cout << endl;
//     }
// }