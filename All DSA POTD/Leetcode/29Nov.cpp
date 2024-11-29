#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumTime(vector<vector<int>> &grid)
    {
        if (grid[0][1] > 1 && grid[1][0] > 1)
            return -1;

        constexpr int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        const int m = grid.size();
        const int n = grid[0].size();
        using T = tuple<int, int, int>; // (time, i, j)
        priority_queue<T, vector<T>, greater<T>> minHeap;
        vector<vector<bool>> seen(m, vector<bool>(n, false));

        minHeap.emplace(0, 0, 0);
        seen[0][0] = true;

        while (!minHeap.empty())
        {
            T current = minHeap.top();
            minHeap.pop();
            int time = get<0>(current);
            int i = get<1>(current);
            int j = get<2>(current);

            if (i == m - 1 && j == n - 1)
                return time;

            for (const auto &dir : dirs)
            {
                int dx = dir[0];
                int dy = dir[1];
                int x = i + dx;
                int y = j + dy;

                if (x < 0 || x >= m || y < 0 || y >= n)
                    continue;
                if (seen[x][y])
                    continue;

                int extraWait = (grid[x][y] - time) % 2 == 0 ? 1 : 0;
                int nextTime = max(time + 1, grid[x][y] + extraWait);
                minHeap.emplace(nextTime, x, y);
                seen[x][y] = true;
            }
        }

        throw runtime_error("Path not found");
    }
};
