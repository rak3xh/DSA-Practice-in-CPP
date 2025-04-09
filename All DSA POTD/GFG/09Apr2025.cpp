#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    void findArticulationPoints(int u, int parent, vector<int> &disc, vector<int> &low,
                                vector<bool> &isArticulation, vector<vector<int>> &adj, int &time)
    {

        disc[u] = low[u] = ++time;
        int children = 0;
        for (auto v : adj[u])
        {
            if (disc[v] == -1)
            { // v is not visited
                children++;

                findArticulationPoints(v, u, disc, low, isArticulation, adj, time);
                low[u] = min(low[u], low[v]);

                // check articulation points
                if (parent == -1 && children > 1)
                    isArticulation[u] = true;
                if (parent != -1 && low[v] >= disc[u])
                    isArticulation[u] = true;
            }
            else if (v != parent)
            { // Back edge
                low[u] = min(low[u], disc[v]);
            }
        }
    }
    vector<int> articulationPoints(int V, vector<vector<int>> &edges)
    {
        // Code here
        vector<vector<int>> adj(V);
        for (auto e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> disc(V, -1), low(V, -1);
        vector<bool> isArticulation(V, false);
        int time = 0;
        for (int i = 0; i < V; i++)
        {
            if (disc[i] == -1)
                findArticulationPoints(i, -1, disc, low, isArticulation, adj, time);
        }

        vector<int> res;
        for (int i = 0; i < V; i++)
            if (isArticulation[i])
                res.push_back(i);
        if (res.empty())
            return {-1};
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        Solution obj;
        vector<int> ans = obj.articulationPoints(V, edges);
        sort(ans.begin(), ans.end());
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}