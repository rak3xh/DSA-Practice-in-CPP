#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(vector<int> &vis, int node, vector<int> adj[], int par,
             unordered_map<int, set<int>> &mp, vector<int> &superParent)
    {
        vis[node] = 1;
        mp[par].insert(node);
        superParent[node] = par;

        for (auto child : adj[node])
        {
            if (!vis[child])
            {
                dfs(vis, child, adj, par, mp, superParent);
            }
        }
    }
    vector<int> processQueries(int c, vector<vector<int>> &connections, vector<vector<int>> &queries)
    {
        vector<int> adj[c + 1];

        for (auto i : connections)
        {
            int u = i[0];
            int v = i[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_map<int, set<int>> mp;
        vector<int> vis(c + 1, 0);
        vector<int> superParent(c + 1, 0);

        for (int i = 1; i <= c; i++)
        {
            if (!vis[i])
            {
                dfs(vis, i, adj, i, mp, superParent);
            }
        }

        vector<int> ans;
        vector<int> online(c + 1, 1);

        for (auto i : queries)
        {
            int type = i[0];
            int node = i[1];
            int par = superParent[node];

            if (type == 1)
            {

                if (online[node])
                {
                    ans.push_back(node);
                }
                else
                {

                    if (mp[par].size() > 0)
                    {
                        ans.push_back(*mp[par].begin());
                    }
                    else
                    {
                        ans.push_back(-1);
                    }
                }
            }
            else
            {
                online[node] = 0;
                mp[par].erase(node);
            }
        }

        return ans;
    }
};