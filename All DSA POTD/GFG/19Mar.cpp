#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class dsu
{
public:
    vector<int> parent;
    vector<int> size;
    // vector<int> rank;
    int n;
    dsu(int n)
    {
        this->n = n;
        parent.resize(n + 1);
        size.resize(n + 1);
        // rank.resize(n+1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
            // rank[i] = 0;
        }
    }
    int findparent(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        return parent[x] = findparent(parent[x]);
    }
    int unionbysize(int x, int y, int &ans)
    {
        int px = findparent(x);
        int py = findparent(y);
        if (px == py)
            return size[px] * size[py];
        if (size[px] > size[py])
        {
            ans += size[px] * size[py];
            parent[py] = px;
            size[px] += size[py];
        }
        else
        {
            ans += size[px] * size[py];
            parent[px] = py;
            size[py] += size[px];
        }
        return ans;
    }
};
class Solution
{
public:
    vector<int> maximumWeight(int n, vector<vector<int>> edges, int q, vector<int> &queries)
    {
        // code here
        int ans = 0;
        dsu d(n);
        vector<pair<int, pair<int, int>>> wt;
        for (int i = 0; i < n - 1; i++)
        {
            wt.push_back({edges[i][2], {edges[i][0], edges[i][1]}});
        }
        sort(wt.begin(), wt.end());
        map<int, int> mp;

        for (int i = 0; i < n - 1; i++)
        {

            int a = wt[i].first;

            int b = wt[i].second.first;

            int c = wt[i].second.second;

            mp[a] = d.unionbysize(b, c, ans);
        }
        vector<int> res;
        for (int i = 0; i < q; i++)
        {
            auto it = mp.upper_bound(queries[i]);
            if (it == mp.begin())
            {
                res.push_back(0);
            }
            else
            {
                it--;
                res.push_back(it->second);
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<vector<int>> edges(n - 1, vector<int>(3, 0));

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cin >> edges[i][j];
            }
        }

        int q;
        cin >> q;
        vector<int> queries(q);
        for (int i = 0; i < q; i++)
            cin >> queries[i];

        Solution obj;
        vector<int> ans = obj.maximumWeight(n, edges, q, queries);

        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}