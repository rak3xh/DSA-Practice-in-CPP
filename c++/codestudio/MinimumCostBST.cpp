#include <bits/stdc++.h>
using namespace std;

int minCostBST(vector<int> &arr, vector<int> &freq)
{
    int n = arr.size();

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({arr[i], freq[i]});
    }

    sort(v.begin(), v.end());

    vector<int> pre(n);
    pre[0] = freq[0];
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + freq[i];
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
        dp[i][i] = v[i].second;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {

            dp[i][j] = INT_MAX;

            for (int k = i; k <= j; k++)
            {
                int l = k > i ? dp[i][k - 1] : 0;
                int r = k < j ? dp[k + 1][j] : 0;
                dp[i][j] = min(dp[i][j], l + r + pre[j] - (i > 0 ? pre[i - 1] : 0));
            }
        }
    }
    return dp[0][n - 1];
}