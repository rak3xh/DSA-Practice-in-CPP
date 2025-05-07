#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minTimeToReach(vector<vector<int>> &moveTime)
    {
        return dijkstra(moveTime, {0, 0}, {int(moveTime.size() - 1), int(moveTime[0].size() - 1)});
    }

private:
    int dijkstra(const vector<vector<int>> &moveTime, const pair<int, int> &src,
                 const pair<int, int> &dst)
    {
        const int kDirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int m = moveTime.size();
        int n = moveTime[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        dist[0][0] = 0;
        typedef pair<int, pair<int, int>> T; // (distance, (x, y))
        priority_queue<T, vector<T>, greater<T>> minHeap;
        minHeap.push(make_pair(dist[0][0], src));

        while (!minHeap.empty())
        {
            T top = minHeap.top();
            minHeap.pop();
            int d = top.first;
            int i = top.second.first;
            int j = top.second.second;

            if (make_pair(i, j) == dst)
                return d;

            if (d > dist[i][j])
                continue;

            for (int k = 0; k < 4; ++k)
            {
                int dx = kDirs[k][0], dy = kDirs[k][1];
                int x = i + dx, y = j + dy;
                if (x < 0 || x >= m || y < 0 || y >= n)
                    continue;
                int newDist = max(moveTime[x][y], d) + 1;
                if (newDist < dist[x][y])
                {
                    dist[x][y] = newDist;
                    minHeap.push(make_pair(newDist, make_pair(x, y)));
                }
            }
        }

        return -1;
    }
};

// C++ 20 Solution
/*
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int minTimeToReach(vector<vector<int>> &moveTime)
    {
        return dijkstra(moveTime, {0, 0},
        {moveTime.size() - 1, moveTime[0].size() - 1});
    }

    private:
    int dijkstra(const vector<vector<int>> &moveTime, const pair<int, int> &src,
    const pair<int, int> &dst)
    {
        constexpr int kDirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        const int m = moveTime.size();
        const int n = moveTime[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        dist[0][0] = 0;
        using T = pair<int, pair<int, int>>; // (d, u)
        priority_queue<T, vector<T>, greater<>> minHeap;
        minHeap.push({dist[0][0], src});

        while (!minHeap.empty())
        {
            const auto [d, u] = minHeap.top();
            minHeap.pop();
            if (u == dst)
            return d;
            const auto [i, j] = u;
            if (d > dist[i][j])
            continue;
            for (const auto &[dx, dy] : kDirs)
            {
                const int x = i + dx;
                const int y = j + dy;
                if (x < 0 || x == m || y < 0 || y == n)
                continue;
                const int newDist = max(moveTime[x][y], d) + 1;
                if (newDist < dist[x][y])
                {
                    dist[x][y] = newDist;
                    minHeap.push({newDist, {x, y}});
                }
            }
        }

        return -1;
    }
};
*/