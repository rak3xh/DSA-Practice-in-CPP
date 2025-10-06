#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
    {
        const int kDirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        const int n = grid.size();
        int ans = grid[0][0];

        typedef tuple<int, int, int> T; // (grid[i][j], i, j)
        priority_queue<T, vector<T>, greater<T>> minHeap;
        vector<vector<bool>> seen(n, vector<bool>(n, false));

        minHeap.emplace(grid[0][0], 0, 0);
        seen[0][0] = true;

        while (!minHeap.empty())
        {
            T top = minHeap.top();
            minHeap.pop();

            int height = get<0>(top);
            int i = get<1>(top);
            int j = get<2>(top);

            ans = max(ans, height);
            if (i == n - 1 && j == n - 1)
                break;

            for (int d = 0; d < 4; ++d)
            {
                int x = i + kDirs[d][0];
                int y = j + kDirs[d][1];

                if (x < 0 || x >= n || y < 0 || y >= n)
                    continue;
                if (seen[x][y])
                    continue;

                minHeap.emplace(grid[x][y], x, y);
                seen[x][y] = true;
            }
        }

        return ans;
    }
};
