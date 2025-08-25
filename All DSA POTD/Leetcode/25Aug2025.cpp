#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        const int m = mat.size();
        const int n = mat[0].size();
        vector<int> ans(m * n);
        int d = 1; // left-bottom -> right-top
        int row = 0;
        int col = 0;

        for (int i = 0; i < m * n; ++i)
        {
            ans[i] = mat[row][col];
            row -= d;
            col += d;
            // out-of-bounds
            if (row == m)
                row = m - 1, col += 2, d = -d;
            if (col == n)
                col = n - 1, row += 2, d = -d;
            if (row < 0)
                row = 0, d = -d;
            if (col < 0)
                col = 0, d = -d;
        }

        return ans;
    }
};