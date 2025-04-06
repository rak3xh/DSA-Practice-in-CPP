#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        // code here
        vector<vector<int>> adj(V + 1);

        for (auto it : edges)
        {
            adj[it[1]].push_back(it[0]);
        }
        vector<int> ans;
        vector<int> vis(V + 1, 0);
        function<void(int)> f = [&](int u) -> void
        {
            vis[u] = 1;
            for (int v : adj[u])
            {
                if (!vis[v])
                {
                    f(v);
                }
            }
            ans.push_back(u);
        };
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                f(i);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int check(int V, vector<int> &res, vector<vector<int>> adj)
{

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);
        vector<vector<int>> edges;

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            edges.push_back({u, v});
        }

        Solution obj;
        vector<int> res = obj.topoSort(V, edges);
        bool ans = check(V, res, adj);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~"
             << "\n";
    }

    return 0;
}