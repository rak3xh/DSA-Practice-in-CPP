#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumObstacles(vector<vector<int>> &grid)
    {
        const int m = grid.size();
        const int n = grid[0].size();
        const int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        using T = tuple<int, int, int>; // (d, i, j)
        priority_queue<T, vector<T>, greater<T>> minHeap;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        minHeap.emplace(grid[0][0], 0, 0);
        dist[0][0] = grid[0][0];

        while (!minHeap.empty())
        {
            int d, i, j;
            tie(d, i, j) = minHeap.top(); // Extract tuple elements
            minHeap.pop();

            if (i == m - 1 && j == n - 1)
                return d;

            for (int k = 0; k < 4; ++k)
            {
                int dx = dirs[k][0], dy = dirs[k][1];
                int x = i + dx, y = j + dy;
                if (x < 0 || x >= m || y < 0 || y >= n)
                    continue;

                int newDist = d + grid[x][y];
                if (newDist < dist[x][y])
                {
                    dist[x][y] = newDist;
                    minHeap.emplace(newDist, x, y);
                }
            }
        }

        return dist[m - 1][n - 1];
    }
};
