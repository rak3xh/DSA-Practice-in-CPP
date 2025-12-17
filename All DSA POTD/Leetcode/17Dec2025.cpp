#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long maximumProfit(vector<int> &prices, int k)
    {
        int n = prices.size();
        // dp[j][0], dp[j][1], dp[j][2] as described
        const long long NEG_INF = LLONG_MIN / 4;

        // Initialize with neutral = 0, others = NEG_INF
        vector<vector<long long>> dp(k + 1, vector<long long>(3, NEG_INF));
        for (int j = 0; j <= k; j++)
        {
            dp[j][0] = 0; // neutral
        }

        // DP
        for (int price : prices)
        {
            // We go backwards on j so earlier states don't use updated values
            for (int j = k; j >= 1; j--)
            {
                long long neutral = dp[j][0];
                long long longPos = dp[j][1];
                long long shortPos = dp[j][2];

                // 1) Remain neutral, or close long/short
                long long newNeutral = max({
                    neutral,
                    longPos + price, // sell long
                    shortPos - price // buy back short
                });

                // 2) Open long (must be from neutral at j-1)
                long long newLong = max(longPos, dp[j - 1][0] - price);

                // 3) Open short (must be from neutral at j-1)
                long long newShort = max(shortPos, dp[j - 1][0] + price);

                dp[j][0] = newNeutral;
                dp[j][1] = newLong;
                dp[j][2] = newShort;
            }
        }

        // result: neutral at up to k transactions
        return dp[k][0];
    }
};