#include <bits/stdc++.h>
using namespace std;

int minimumHp(int n, int m, vector<vector<int>> &board)
{

    vector<vector<int>> dp(n, vector<int>(m));
    // The value at bottom-right should be 1 or more
    dp[n - 1][m - 1] = max(1, 1 - board[n - 1][m - 1]);

    // Initialize the last row
    for (int j = m - 2; j >= 0; j--)
    {
        dp[n - 1][j] = max(1, dp[n - 1][j + 1] - board[n - 1][j]);
    }

    // Initialize the last column
    for (int i = n - 2; i >= 0; i--)
    {
        dp[i][m - 1] = max(1, dp[i + 1][m - 1] - board[i][m - 1]);
    }

    // Fill up the DP table
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = m - 2; j >= 0; j--)
        {
            int minOnExit = min(dp[i + 1][j], dp[i][j + 1]);
            dp[i][j] = max(1, minOnExit - board[i][j]);
        }
    }

    return dp[0][0];
}
