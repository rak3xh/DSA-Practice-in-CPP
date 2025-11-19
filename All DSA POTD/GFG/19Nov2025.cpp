#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int minCostPath(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> cost(n, vector<int>(m, INT_MAX));
        cost[0][0] = 0;

        // priority_queue<cost, {x, y}>
        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>>
            pq;

        pq.push({0, {0, 0}});

        while (!pq.empty())
        {
            pair<int, pair<int, int>> top = pq.top();
            pq.pop();

            int currCost = top.first;
            int x = top.second.first;
            int y = top.second.second;

            // Skip outdated entry
            if (currCost != cost[x][y])
                continue;

            // Destination reached
            if (x == n - 1 && y == m - 1)
                return currCost;

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m)
                {
                    // max diff on path
                    int newCost = max(currCost, abs(mat[nx][ny] - mat[x][y]));

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
