#include <bits/stdc++.h>
using namespace std;
bool dfs(int i, vector<vector<int>> &mat, vector<int> &vis, vector<int> &dp)
{
    for (int j = 0; j < mat[0].size(); j++)
    {
        if (mat[i][j] and dp[j] == 0)
        {
            dp[j] = 1;
            if (vis[j] == -1 or dfs(vis[j], mat, vis, dp))
            {
                vis[j] = i;
                return true;
            }
        }
    }
    return false;
}
int maxMatch(vector<vector<int>> &mat)
{
    int n = mat.size(), m = mat[0].size(), cnt = 0;
    vector<int> vis(m, -1);
    for (int i = 0; i < n; i++)
    {
        vector<int> dp(m, 0);
        if (dfs(i, mat, vis, dp))
        {
            cnt++;
        }
    }
    return cnt;
}