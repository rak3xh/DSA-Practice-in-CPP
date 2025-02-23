#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int dieSimulator(int n, vector<int> &rollMax)
    {
        const int kMaxRolls = 15;
        const int kMod = 1000000007;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(6, vector<int>(kMaxRolls + 1, 0)));

        for (int num = 0; num < 6; ++num)
        {
            dp[1][num][1] = 1;
        }

        for (int i = 2; i <= n; ++i)
        {
            for (int currNum = 0; currNum < 6; ++currNum)
            {
                for (int prevNum = 0; prevNum < 6; ++prevNum)
                {
                    for (int k = 1; k <= kMaxRolls; ++k)
                    {
                        if (prevNum != currNum)
                        {
                            dp[i][currNum][1] = (dp[i][currNum][1] + dp[i - 1][prevNum][k]) % kMod;
                        }
                        else if (k < rollMax[currNum])
                        {
                            dp[i][currNum][k + 1] = dp[i - 1][currNum][k];
                        }
                    }
                }
            }
        }

        int ans = 0;

        for (int num = 0; num < 6; ++num)
        {
            for (int k = 1; k <= kMaxRolls; ++k)
            {
                ans = (ans + dp[n][num][k]) % kMod;
            }
        }

        return ans;
    }
};