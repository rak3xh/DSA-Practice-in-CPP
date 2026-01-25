#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findWays(int n)
    {
        // code here
        if (n % 2)
            return 0;

        int k = n / 2 + 1;
        vector<vector<int>> dp(k, vector<int>(k, 0));

        for (int i = 0; i < k; i++)
            dp[0][i] = 1;

        for (int i = 1; i < k; i++)
        {
            for (int j = i; j < k; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[k - 1][k - 1];
    }
};