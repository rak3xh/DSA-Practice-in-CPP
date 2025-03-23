// C++ 14 Solution
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<vector<pair<int, int>>> graph(n);

        for (const vector<int> &road : roads)
        {
            int u = road[0];
            int v = road[1];
            int w = road[2];
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }

        return dijkstra(graph, 0, n - 1);
    }

private:
    int dijkstra(const vector<vector<pair<int, int>>> &graph, int src, int dst)
    {
        const int kMod = 1000000007;
        vector<long> ways(graph.size(), 0);
        vector<long> dist(graph.size(), LONG_MAX);

        ways[src] = 1;
        dist[src] = 0;

        using P = pair<long, int>; // (distance, node)
        priority_queue<P, vector<P>, greater<P>> minHeap;
        minHeap.emplace(0, src);

        while (!minHeap.empty())
        {
            pair<long, int> top = minHeap.top();
            minHeap.pop();
            long d = top.first;
            int u = top.second;

            if (d > dist[u])
                continue;

            for (const auto &edge : graph[u])
            {
                int v = edge.first;
                int w = edge.second;

                if (d + w < dist[v])
                {
                    dist[v] = d + w;
                    ways[v] = ways[u];
                    minHeap.emplace(dist[v], v);
                }
                else if (d + w == dist[v])
                {
                    ways[v] = (ways[v] + ways[u]) % kMod;
                }
            }
        }

        return ways[dst];
    }
};

// C++ 20 Solution
/*
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<vector<pair<int, int>>> graph(n);

        for (const vector<int> &road : roads)
        {
            const int u = road[0];
            const int v = road[1];
            const int w = road[2];
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }

        return dijkstra(graph, 0, n - 1);
    }

    private:
    // Similar to 1786. Number of Restricted Paths From First to Last Node
    int dijkstra(const vector<vector<pair<int, int>>> &graph, int src, int dst)
    {
        constexpr int kMod = 1'000'000'007;
        vector<long> ways(graph.size());
        vector<long> dist(graph.size(), LONG_MAX);

        ways[src] = 1;
        dist[src] = 0;
        using P = pair<long, int>; // (d, u)
        priority_queue<P, vector<P>, greater<>> minHeap;
        minHeap.emplace(dist[src], src);

        while (!minHeap.empty())
        {
            const auto [d, u] = minHeap.top();
            minHeap.pop();
            if (d > dist[u])
            continue;
            for (const auto &[v, w] : graph[u])
            if (d + w < dist[v])
            {
                dist[v] = d + w;
                ways[v] = ways[u];
                minHeap.emplace(dist[v], v);
            }
            else if (d + w == dist[v])
            {
                ways[v] += ways[u];
                ways[v] %= kMod;
            }
        }

        return ways[dst];
    }
};
*/