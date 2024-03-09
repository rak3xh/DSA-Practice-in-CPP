#include <bits/stdc++.h>
using namespace std;

int largestSquareSubmatrix(vector<vector<int>> &mat, int n, int m, int k)
{
    // Write your code here.
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            dp[i + 1][j + 1] = mat[i][j] + dp[i + 1][j] + dp[i][j + 1] - dp[i][j];
        }
    }

    int res = min(n, m);
    int sum = 0;

    for (int l = res; l >= 0; l--)
    {
        for (int i = l; i < n + 1; i++)
        {
            for (int j = l; j < m + 1; j++)
            {

                sum = dp[i][j] + dp[i - l][j - l] - dp[i - l][j] - dp[i][j - l];

                if (sum <= k)
                {
                    return l * l;
                }
            }
        }
    }
    return 0;
}
