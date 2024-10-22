#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 7;
vector<pair<int, int>> g[N];
vector<pair<int, int>> g1[N];
int dist[N];
int dist1[N];

void Djkstra(int &s)
{
    set<pair<int, int>> st;
    st.insert({s, 0});
    dist[s] = 0;

    while (!st.empty())
    {
        auto it = *(st.begin());
        int nd = it.first;
        int wt = it.second;
        st.erase(it);
        for (auto &a : g[nd])
        {
            int n_nd = a.first;
            int n_wt = a.second;
            if (wt + n_wt < dist[n_nd])
            {
                if (dist[n_nd] != 1e9)
                    st.erase({n_nd, dist[n_nd]});
                dist[n_nd] = wt + n_wt;
            }
            st.insert({n_nd, dist[n_nd]});
        }
    }
}

void Djkstra1(int &s)
{
    set<pair<int, int>> st;
    st.insert({s, 0});
    dist1[s] = 0;

    while (!st.empty())
    {
        auto it = *(st.begin());
        int nd = it.first;
        int wt = it.second;
        st.erase(it);
        for (auto &a : g1[nd])
        {
            int n_nd = a.first;
            int n_wt = a.second;
            if (wt + n_wt < dist1[n_nd])
            {
                if (dist1[n_nd] != 1e9)
                    st.erase({n_nd, dist1[n_nd]});
                dist1[n_nd] = wt + n_wt;
            }
            st.insert({n_nd, dist1[n_nd]});
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        for (int i = 0; i < N; ++i)
        {
            g[i].clear();
            g1[i].clear();
            dist[i] = 1e9;
            dist1[i] = 1e9;
        }

        int v, e, s, t, p;
        cin >> v >> e >> s >> t >> p;
        // s--;
        // t--;
        // vector<vector<int>> nw;
        for (int i = 0; i < e; ++i)
        {
            int a, b, c;
            cin >> a >> b >> c;
            // u--;
            // v--;
            g[a].push_back({b, c});
            g1[b].push_back({a, c});
            // nw.push_back({a, c, b});
        }

        Djkstra(s);
        Djkstra1(t);

        // set<pair<int, int>> st;
        // st.insert({s, 0});
        // dist[s] = 0;

        // while (!st.empty())
        // {
        //     auto it = *(st.begin());
        //     int nd = it.first;
        //     int wt = it.second;
        //     st.erase(it);
        //     for (auto a : g[nd])
        //     {
        //         int n_nd = a.first;
        //         int n_wt = a.second;
        //         if (wt + n_wt < dist[n_nd])
        //         {
        //             if (dist[n_nd] != 1e9)
        //                 st.erase({n_nd, dist[n_nd]});
        //             dist[n_nd] = wt + n_wt;
        //         }
        //         st.insert({n_nd, dist[n_nd]});
        //     }
        // }
        int ans = -1;

        for (int i = 1; i <= v; ++i)
        {
            for (auto pr : g[i])
            {
                int x, y, z;
                x = i;
                y = pr.first;
                z = pr.second;
                if (dist[x] + z + dist1[y] <= p)
                    ans = max(ans, z);
            }
        }

        // for (auto &i : nw)
        // {
        //     int x, y, z;
        //     x = i[0];
        //     y = i[2];
        //     z = i[1];
        //     if (dist[x] + z + dist1[y] <= p)
        //         ans = max(ans, z);
        // }

        cout << ans << endl;
    }
}

// 2
// 5 6 1 5 10
// 1 2 7
// 2 5 4
// 1 3 6
// 3 5 3
// 1 4 5
// 4 5 4
// 2 1 1 2 10
// 1 2 20