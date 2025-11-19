#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int minCostPath(vector<vector<int>> &mat)
    {
        // code here
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> cost(n, vector<int>(m, INT_MAX));
        cost[0][0] = 0;

        // {current cost, {x, y}}
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, greater<>>
            pq;
        pq.push({0, {0, 0}});

        while (!pq.empty())
        {
            auto [currCost, cell] = pq.top();
            pq.pop();
            int x = cell.first, y = cell.second;

            // Skip if this is an outdated entry
            if (currCost != cost[x][y])
                continue;

            // Destination reached
            if (x == n - 1 && y == m - 1)
                return currCost;

            for (auto d : dir)
            {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m)
                {

                    // Maximum difference along this path
                    int newCost = max(currCost, abs(mat[nx][ny] - mat[x][y]));

                    // Update if newCost improves the neighbor
                    if (newCost < cost[nx][ny])
                    {
                        cost[nx][ny] = newCost;
                        pq.push({newCost, {nx, ny}});
                    }
                }
            }
        }

        return cost[n - 1][m - 1];
    }
};
