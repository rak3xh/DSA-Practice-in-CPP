#include <bits/stdc++.h>
using namespace std;
int M = 1e9 + 7;
int f(int i, int j, int k, const string &A, const string &B, const string &C, vector<vector<vector<int>>> &dp)
{
    if (k == 0)
        return 1;
    if (dp[i][j][k] != -1)
        return dp[i][j][k];
    int ans = 0;
    for (int t = i; t > 0; t--)
    {
        if (A[t - 1] == C[k - 1])
        {
            ans = (ans + f(t - 1, j, k - 1, A, B, C, dp)) % M;
        }
    }
    for (int t = j; t > 0; t--)
    {
        if (B[t - 1] == C[k - 1])
        {
            ans = (ans + f(i, t - 1, k - 1, A, B, C, dp)) % M;
        }
    }
    return dp[i][j][k] = ans;
}
int countWays(string A, string B, string C)
{
    int x = A.size(), y = B.size(), z = C.size();
    vector<vector<vector<int>>> dp(x + 1, vector<vector<int>>(y + 1, vector<int>(z + 1, -1)));
    return f(x, y, z, A, B, C, dp);
}