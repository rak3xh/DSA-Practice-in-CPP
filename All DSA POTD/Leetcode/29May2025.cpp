#include <bits/stdc++.h>
using namespace std;
class Solution
{
#define pii pair<int, int>

    // A single BFS that:
    // 1) returns the number of nodes on even-numbered levels, and
    // 2) if `included` is non-null, marks exactly those nodes at even levels
    int bfs(int start,
            const vector<vector<int>> &adj,
            vector<bool> *included = nullptr)
    {
        queue<pii> q;
        q.push({start, -1});
        int count = 0;
        int level = 0;

        while (!q.empty())
        {
            int size = q.size();
            // on even levels we both add to count and (optionally) record the nodes
            if (level % 2 == 0)
                count += size;

            while (size--)
            {
                auto [curr, parent] = q.front();
                q.pop();
                if (included && level % 2 == 0)
                {
                    // mark this node as “included”
                    (*included)[curr] = true;
                }
                for (int v : adj.at(curr))
                {
                    if (v == parent)
                        continue;
                    q.push({v, curr});
                }
            }
            ++level;
        }
        return count;
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2)
    {
        // build adjacency lists
        int n1 = edges1.size() + 1;
        int n2 = edges2.size() + 1;
        vector<vector<int>> adj1(n1 + 1), adj2(n2 + 1);

        for (auto &edge : edges1)
        {
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }
        for (auto &edge : edges2)
        {
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }

        // Step-1: Find the best you can do by adding the extra edge in tree-2
        int even_count2 = bfs(0, adj2);    // count of even-level nodes
        int odd_count2 = n2 - even_count2; // the rest are odd-level
        int best2 = max(even_count2, odd_count2);

        // Step-2: Run BFS on tree-1, and record nodes on even levels
        vector<bool> included(n1, false);
        int even_count1 = bfs(0, adj1, &included);

        // Step-3: For each i, if i was even-level in tree-1 we connect it to tree-2's best even-level
        vector<int> ans(n1);
        for (int i = 0; i < n1; ++i)
        {
            if (included[i])
            {
                // it contributes even_count1 from tree-1 plus best2 from tree-2
                ans[i] = even_count1 + best2;
            }
            else
            {
                // it would be odd in tree-1, so you get (n1-even_count1) + best2
                ans[i] = (n1 - even_count1) + best2;
            }
        }
        return ans;
    }
};