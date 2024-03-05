#include <bits/stdc++.h>
using namespace std;
void dfs(int u, vector<int> &disc, vector<int> &low, stack<pair<int, int>> &st, vector<int> &parent, vector<vector<int>> &adj, int &count)
{

    /*
        A static variable is used for simplicity, we can avoid use
        of static variable by passing a pointer.
    */
    static int time = 0;

    // Initialize discovery time and low value.
    disc[u] = low[u] = ++time;
    int children = 0;

    // Go through all vertices adjacent to this.
    for (int v : adj[u])
    {

        // If v is not visited yet, then recur for it.
        if (disc[v] == -1)
        {
            children++;
            parent[v] = u;

            // store the edge in stack.
            st.push(pair<int, int>(u, v));
            dfs(v, disc, low, st, parent, adj, count);

            /*
                Check if the subtree rooted with 'v' has a
                connection to one of the ancestors of 'u'.
            */
            low[u] = min(low[u], low[v]);

            /*
                If u is an articulation point,
                pop all edges from stack till u -- v.
            */
            if ((disc[u] == 1 && children > 1) || (disc[u] > 1 && low[v] >= disc[u]))
            {
                while (st.top().first != u || st.top().second != v)
                {
                    st.pop();
                }
                st.pop();
                count++;
            }
        }

        /*
            Update low value of 'u' only of 'v' is still in stack
            (i.e. it's a back edge, not cross edge).
        */
        else if (v != parent[u])
        {
            low[u] = min(low[u], disc[v]);
            if (disc[v] < disc[u])
            {
                st.push(pair<int, int>(u, v));
            }
        }
    }
}

int biconnectedComponents(int n, int m, vector<pair<int, int>> &edges)
{
    vector<vector<int>> adj(n + 1);

    // Storing edges in adjacency list.
    for (auto &x : edges)
    {
        adj[x.first].push_back(x.second);
        adj[x.second].push_back(x.first);
    }

    int count = 0;

    vector<int> disc(n + 1, -1);
    vector<int> low(n + 1, -1);
    vector<int> parent(n + 1, -1);
    stack<pair<int, int>> st;

    for (int i = 1; i <= n; i++)
    {
        if (disc[i] == -1)
            dfs(i, disc, low, st, parent, adj, count);

        // If stack is not empty, pop all edges from stack.
        if (st.size() > 0)
        {
            count++;
        }

        while (st.size() > 0)
        {
            st.pop();
        }
    }

    return count;
}