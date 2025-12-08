#include <bits/stdc++.h>
using namespace std;
int mod = 1000000000 + 7;
#define ll long long
class Solution
{
public:
    int n;
    int distinctSubseq(string &str)
    {
        // code here
        n = str.size();
        vector<int> dp(n + 1, 1);
        vector<int> prev(26, -1);
        dp[0] = 1; // empty subsequence
        for (int i = 1; i <= n; i++)
        {
            int ch = str[i - 1] - 'a';
            dp[i] = (2 * 1ll * dp[i - 1]) % mod;

            if (prev[ch] != -1)
            {
                dp[i] = (dp[i] - dp[prev[ch]] + mod) % mod;
            }

            prev[ch] = i - 1;
        }
        return dp[n];
    }
};