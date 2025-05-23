#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(int n, int sum, int &m, int &x, vector<vector<int>> &dp)
    {
        if (n == 0 and sum == x)
            return 1;
        if (n == 0 or sum > x)
            return 0;
        if (dp[n][sum] != -1)
            return dp[n][sum];
        int cnt = 0;
        for (int i = 1; i <= m; i++)
            cnt += solve(n - 1, sum + i, m, x, dp);
        return dp[n][sum] = cnt;
    }
    int noOfWays(int m, int n, int x)
    {
        // code here
        vector<vector<int>> dp(n + 1, vector<int>(x + 1, -1));
        return solve(n, 0, m, x, dp);
    }
};