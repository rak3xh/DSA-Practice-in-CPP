#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int latestDayToCross(int row, int col, vector<vector<int>> &cells)
    {
        int ans = 0;
        int l = 1;
        int r = (int)cells.size() - 1;

        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (canWalk(m, row, col, cells))
            {
                ans = m;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        return ans;
    }

private:
    static const int kDirs[4][2];

    bool canWalk(int day, int row, int col, const vector<vector<int>> &cells)
    {
        vector<vector<int>> matrix(row, vector<int>(col, 0));

        for (int i = 0; i < day; ++i)
        {
            int x = cells[i][0] - 1;
            int y = cells[i][1] - 1;
            matrix[x][y] = 1;
        }

        queue<pair<int, int>> q;

        for (int j = 0; j < col; ++j)
        {
            if (matrix[0][j] == 0)
            {
                q.push(make_pair(0, j));
                matrix[0][j] = 1;
            }
        }

        while (!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();
            int i = cur.first;
            int j = cur.second;

            for (int d = 0; d < 4; ++d)
            {
                int x = i + kDirs[d][0];
                int y = j + kDirs[d][1];

                if (x < 0 || x >= row || y < 0 || y >= col)
                    continue;
                if (matrix[x][y] == 1)
                    continue;
                if (x == row - 1)
                    return true;

                q.push(make_pair(x, y));
                matrix[x][y] = 1;
            }
        }
        return false;
    }
};

const int Solution::kDirs[4][2] = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}};
