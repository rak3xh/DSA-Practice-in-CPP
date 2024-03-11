#include <bits/stdc++.h>
using namespace std;

int func(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{

    if (i == r - 1)
    {

        if (j1 != j2)
        {

            return grid[r - 1][j1] + grid[r - 1][j2];
        }

        return grid[r - 1][j1];
    }

    if (dp[i][j1][j2] != -1)
    {

        return dp[i][j1][j2];
    }

    int maxi = INT_MIN;

    for (int k1 = -1; k1 < 2; k1++)
    {

        for (int k2 = -1; k2 < 2; k2++)
        {

            if (j1 + k1 < c && j1 + k1 >= 0 && j2 + k2 < c && j2 + k2 >= 0)
            {

                int ans = grid[i][j1] + grid[i][j2] + func(i + 1, j1 + k1, j2 + k2, r, c, grid, dp);

                if (j1 == j2)
                {

                    ans -= grid[i][j1];
                }

                maxi = max(ans, maxi);
            }
        }
    }

    return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{

    vector<vector<vector<int>>> dp(

        r, vector<vector<int>>(c, vector<int>(c, -1)));

    return func(0, 0, c - 1, r, c, grid, dp);
}