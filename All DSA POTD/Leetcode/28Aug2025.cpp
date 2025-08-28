// C++ 14 Solution
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> sortMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> ans(n, vector<int>(n));
        vector<vector<int>> diag(2 * n + 1);

        // Collect elements by diagonals
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                diag[i - j + n].push_back(grid[i][j]);
            }
        }

        // Sort diagonals
        for (int i = 0; i < 2 * n + 1; ++i)
        {
            if (i < n)
                sort(diag[i].begin(), diag[i].end(), greater<int>()); // descending
            else
                sort(diag[i].begin(), diag[i].end()); // ascending
        }

        // Fill result matrix
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                ans[i][j] = diag[i - j + n].back();
                diag[i - j + n].pop_back();
            }
        }

        return ans;
    }
};

// C++ 20 Solution
// class Solution
// {
// public:
//     vector<vector<int>> sortMatrix(vector<vector<int>> &grid)
//     {
//         const int n = grid.size();
//         vector<vector<int>> ans(n, vector<int>(n));
//         vector<vector<int>> diag(2 * n + 1);

//         for (int i = 0; i < n; ++i)
//             for (int j = 0; j < n; ++j)
//                 diag[i - j + n].push_back(grid[i][j]);

//         for (int i = 0; i < 2 * n + 1; ++i)
//             if (i < n)
//                 ranges::sort(diag[i], greater<int>());
//             else
//                 ranges::sort(diag[i]);

//         for (int i = 0; i < n; ++i)
//             for (int j = 0; j < n; ++j)
//                 ans[i][j] = diag[i - j + n].back(), diag[i - j + n].pop_back();

//         return ans;
//     }
// };