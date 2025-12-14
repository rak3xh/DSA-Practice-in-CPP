#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> prefixSum2D(vector<vector<int>> &mat, vector<vector<int>> &queries)
    {
        // code here
        vector<int> result;
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> pref(m + 1, vector<int>(n + 1, 0));
        // calculating prefix sum
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                pref[i][j] = mat[i - 1][j - 1] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
            }
        }

        // query sum

        for (int i = 0; i < queries.size(); i++)
        {
            int r1 = queries[i][0];
            int c1 = queries[i][1];
            int r2 = queries[i][2];
            int c2 = queries[i][3];

            int ans = pref[r2 + 1][c2 + 1] - pref[r1][c2 + 1] - pref[r2 + 1][c1] + pref[r1][c1];
            result.push_back(ans);
        }

        return result;
    }
};
