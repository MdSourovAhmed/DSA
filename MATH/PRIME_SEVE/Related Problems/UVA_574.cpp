
// // #include <bits/stdc++.h>
// // using namespace std;
// // const int N = 1e7 + 7;

// // int main()
// // {
// //     int t;
// //     while (cin >> t)
// //     {
// //         if (!t)
// //             return 0;
// //         int n;
// //         cin >> n;
// //         vector<int> v(n);
// //         for (int &i : v)
// //             cin >> i;
// //         long long b = 1 << n;
// //         set<vector<int>> ans;
// //         for (long long i = 0; i < b; ++i)
// //         {
// //             int lg = log2(i) + 1;
// //             int s = 0;
// //             vector<int> tmp;
// //             string st = "";
// //             for (int j = 0; j < lg; j++)
// //             {
// //                 if (i & (1 << j))
// //                 {
// //                     s += v[j];
// //                     // st+=(to_string(v[j])+"+");
// //                     tmp.push_back(v[j]);
// //                 }
// //             }

// //             if (s == t)
// //                 ans.insert(tmp);
// //         }

// //         printf("Sum of %d:\n", t);
// //         if (!ans.size())
// //         {
// //             cout << "NONE\n";
// //             continue;
// //         }
// //         vector<vector<int>>vv;
// //         for (auto &x : ans)
// //         {
// //             vv.push_back(x);
// //         }

// //         ans.clear();
// //         sort(vv.rbegin(),vv.rend());

// //         for (auto &x : vv)
// //         {
// //             for (int i = 0; i < x.size(); ++i)
// //             {
// //                 cout << x[i];
// //                 if (i != x.size() - 1)
// //                     cout << "+";
// //             }

// //             cout << endl;
// //         }
// //         cout << endl;
// //     }
// // }

// #include <bits/stdc++.h>
// using namespace std;

// // Function to find all subsets of given set. Any repeated
// // subset is considered only once in the output
// vector<vector<int>> findPowerSet(vector<int> &nums, int t)
// {
//     int bits = nums.size();

//     unsigned int pow_set_size = pow(2, bits);

//     // sort(nums.begin(), nums.end());
//     vector<vector<int>> ans;

//     vector<string> list;

//     for (int counter = 0; counter < pow_set_size;
//          counter++)
//     {
//         vector<int> subset;
//         string temp = "";
//         long long sum = 0;

//         for (int j = 0; j < bits; j++)
//         {
//             if (counter & (1 << j))
//             {
//                 subset.push_back(nums[j]);

//                 sum += nums[j];
//                 temp += to_string(nums[j]) + '+';
//             }
//         }

//         if (sum == t && find(list.begin(), list.end(), temp) == list.end())
//         {
//             sort(subset.rbegin(),subset.rend());
//             ans.push_back(subset);
//             list.push_back(temp);
//         }
//     }

//     return ans;
// }

// int main()
// {
//     int t;
//     while (cin >> t)
//     {
//         if (!t)
//             return 0;
//         int n;
//         cin >> n;
//         vector<int> arr(n);
//         for (int &i : arr)
//             cin >> i;

//         vector<vector<int>> ans = findPowerSet(arr, t);

//         sort(ans.rbegin(), ans.rend());
//         printf("Sums of %d:\n", t);
//         if (!ans.size())
//         {
//             cout << "NONE\n";
//             continue;
//         }

//         for (int i = 0; i < ans.size(); i++)
//         {
//             for (int j = 0; j < ans[i].size(); j++)
//             {
//                 if (j)
//                     cout << "+";
//                 cout << ans[i][j];
//             }
//             cout << endl;
//         }
//     }
// }





#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 7;

int main()
{
    int t;
    while (cin >> t)
    {
        if (!t)
            return 0;
        int n;
        cin >> n;
        vector<int> v(n);
        for (int &i : v)
            cin >> i;
        long long b = 1 << n;
        set<vector<int>> ans;
        for (long long i = 0; i < b; ++i)
        {
            int lg = log2(i) + 1;
            int s = 0;
            vector<int> tmp;
            // string st = "";
            for (int j = 0; j < lg; j++)
            {
                if (i & (1 << j))
                {
                    s += v[j];
                    tmp.push_back(v[j]);
                }
            }

            if (s == t)
            {
                sort(tmp.rbegin(), tmp.rend());
                ans.insert(tmp);
            }
        }

        printf("Sums of %d:\n", t);
        if (!ans.size())
        {
            cout << "NONE\n";
            continue;
        }
        vector<vector<int>> vv;
        for (auto &x : ans)
        {
            vv.push_back(x);
        }

        ans.clear();
        sort(vv.rbegin(), vv.rend());

        for (auto &x : vv)
        {
            for (int i = 0; i < x.size(); ++i)
            {
                if (i)
                    cout << "+";
                cout << x[i];
            }

            cout << endl;
        }
    }
}
