#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (const string &s : strs)
        {
            const int zeros = count(s.begin(), s.end(), '0');
            const int ones = s.length() - zeros;
            for (int i = m; i >= zeros; --i)
                for (int j = n; j >= ones; --j)
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
        }

        return dp[m][n];
    }
};