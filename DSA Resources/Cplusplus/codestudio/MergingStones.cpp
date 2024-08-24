#include <bits/stdc++.h>
using namespace std;

int mergeStones(vector<int> &stones, int k)
{

    int n = stones.size();

    if ((n - 1) % (k - 1) != 0)
    {

        return -1; // It is not possible to merge the stones.
    }

    vector<int> prefixSum(n + 1);

    for (int i = 0; i < n; i++)
    {

        prefixSum[i + 1] = prefixSum[i] + stones[i];
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = k; len <= n; len++)
    {

        for (int i = 0; i + len <= n; i++)
        {

            int j = i + len - 1;

            dp[i][j] = INT_MAX;

            for (int m = i; m < j; m += k - 1)
            {

                dp[i][j] = min(dp[i][j], dp[i][m] + dp[m + 1][j]);
            }

            if ((len - 1) % (k - 1) == 0)
            {

                dp[i][j] += prefixSum[j + 1] - prefixSum[i];
            }
        }
    }

    return dp[0][n - 1];
}