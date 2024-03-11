#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool bfs(vector<vector<int>> &residualGraph, int src, int dest, vector<int> &parent)
{

    int n = residualGraph.size();

    vector<bool> visited(n, false);

    queue<int> q;

    q.push(src);

    visited[src] = true;

    parent[src] = -1;

    while (!q.empty())
    {

        int u = q.front();

        q.pop();

        for (int v = 0; v < n; v++)
        {

            if (!visited[v] && residualGraph[u][v] > 0)
            {

                q.push(v);

                parent[v] = u;

                visited[v] = true;
            }
        }
    }

    return visited[dest];
}

int fordFulkerson(int n, vector<vector<int>> &graph, int src, int dest)
{

    vector<vector<int>> residualGraph(graph);

    vector<int> parent(n, -1);

    int maxFlow = 0;

    while (bfs(residualGraph, src, dest, parent))
    {

        int pathFlow = INT_MAX;

        for (int v = dest; v != src; v = parent[v])
        {

            int u = parent[v];

            pathFlow = min(pathFlow, residualGraph[u][v]);
        }

        for (int v = dest; v != src; v = parent[v])
        {

            int u = parent[v];

            residualGraph[u][v] -= pathFlow;

            residualGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int findMaxFlow(int n, int m, vector<vector<int>> &pipes)
{

    vector<vector<int>> graph(n, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {

        int from = pipes[i][0] - 1;

        int to = pipes[i][1] - 1;

        int capacity = pipes[i][2];

        graph[from][to] += capacity;

        graph[to][from] += capacity;
    }

    return fordFulkerson(n, graph, 0, n - 1);
}
